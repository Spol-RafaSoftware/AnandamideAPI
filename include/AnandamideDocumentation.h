//------------------------------------------------------------------------------
//
// This file is part of AnandamideAPI Script
//
// copyright:	(c) 2010 - 2016
// author:		Alexey Egorov (FadeToBlack aka EvilSpirit)
// mailto:		anandamide@mail.ru
// 				anandamide.script@gmail.com
//
// AnandamideAPI is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// AnandamideAPI is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with AnandamideAPI. If not, see <http://www.gnu.org/licenses/>.
//
//------------------------------------------------------------------------------

/*!
\mainpage Документация AnandamideAPI

\section intro Введение

Библиотека AnandamideAPI служит для работы с объектами скриптового языка Anandamide. Функции и классы этой
библиотеки служат для создания, редактирования и запуска скриптовых программ на основе блочного представления.

\section blocks Блоки

Блок является основной составляющей скриптового языка. Блоки могут быть связаны между собой для осуществления контроля
потока исполнения и потока данных. 

\image html block.png "Составляющие блока"

\section program_flow Потоки исполенения.

Блок может содержать действия (actions) и события (events). Эти сущности обеспечивают управление ходом выполенения программы
(передачу управления другому блоку, ветвления, циклы). Обычно программа начинает свое выполенение с определенного места (точка входа).
Дальнейшее поведение программы зависит от того, на какой блок поступает поток исполенения. В зависимости от внутренней логики блока, 
его действия (входящий поток исполения) могут порождать одно или несколько событий (исходящий поток исполенения). 
Одно или множество событий одного блока могут быть связаны с одним или несколькими действиями другого блока. Если одно
событие блока связано с несколькими действиями, то порядок их выполнения не определен. Для однозначного определения порядка
необходимо пользоваться специальными разветвлящими блоками (Sequence). Одно действие блока может активироваться от произвольного
количества событий.

\subsection flow_function Функциональные блоки (Functions)
Обычно большинство блоков содержат только одно действие (in) и одно событие (out), которое вызывается после того, как 
логика работы блока завершена. Такие блоки являются полным аналогом функций или процедур из языков программирования. 

\image html function_blocks.png "Функциональные блоки Message"

\subsection flow_branching Блоки ветвлений (Branching)
Блоки могут содержать один вход и несколко выходов, которые могут активироваться в зависимости от входных параметров или иных условий. 
Такие блоки обеспечивают ветвление. 

\image html branching_blocks.png "Блок условного ветвления If"

\subsection flow_cycles Блоки циклов (Cycles)
Блоки могут вызывать одно событие несколько раз, за счет чего обеспечиваются реализация циклов.

\image html cycle_blocks.png "Блок цикла For"

\subsection flow_events Блоки асинхронных событий (Async Events)
Блоки могут вызывать событие вне зависимости от входных действий или параметров, асинхронно.

\image html async_blocks.png "Блок асинхронных событий нажатия/отпускания клавиши"

\section data_flow Потоки данных.

Блок может содержать входные (input), выходные (output) и внутренние (parameters) параметры. 
Эти параметры могут иметь различный тип принимаемого или возвращаемого значения. 
В визуальном редакторе скриптов на основе блоков эти параметры имеют различный цвет отображения и пиктограммы. 
Один выходной параметр может быть связан с несколькими входными параметрами, но один входной параметр может
быть связан только с одним выходным. Если входной параметр не имеет связи с источником данных (выходным параметром),
ему может быть присвоено значение по умолчанию, которое может быть задано при выделении блока в визуальном редакторе. 
Так же при выделении блока могут быть заданы скрытые параметры блока, которые могут влиять на количество действий, 
событий, входных или выходных параметров и прочую логику поведения блока.

\subsection flow_evaluators Блоки вычислений (Evaluators)
Блоки могут не иметь ни входящих, ни исходящих потоков исполенения. Эти блоки в неявном виде имеют действие, которое
происходит при запросе выходного параметра. Это действие должно обеспечивать вычисление и установку нового значения 
требуемого выходного параметра. Такие блоки могут быть ислользованы для вычисления значений математических выражений. 
Такое поведение используется для того, чтобы исключить двойное соединение блоков (параллельное соединение потока 
исполнения и потока данных)

\image html evaluator_blocks.png "Вычислительные блоки операций сложения, умножения и деления"

\subsection flow_parameters Блоки с переменных числом выводов (Parametric Blocks)

Внутренние параметры могут быть использованы для того, чтобы задавать количество выводов блоков.

\image html parametric_blocks.png "Блок с переменным числом событий Switch"

\section data_types Типы данных.

Входные, выходные и скрытые параметры блоков могут харанить и передавать различные данные заданного типа. Некоторые блоки
передают и принимают значения любого типа (Variable). 

\subsection base_types Базовые типы данных
Существует несколько системных типов данных, которые вшиты в систему переменных (Variable).
	- int - целое
	- float - число с плавающей точкой одинарной точности
	- double - число с плавающей точкой двойной точности
	- string - строка символов
	- Enum - тип перечисления
	- Variable	- универсальный тип, который может сохранять любой тип данных
	
Каждый типа данных имеет визуальные аттрибуты (цвет и пиктограмму) для облегчения визуальной идентификации типа в 
редакторе блочных скриптов.

\subsection user_types Пользовательские типы данных
Библиотека AnandamideAPI поддерживает регистрацию пользовательских типов данных, в том числе автоматическое пробрасывание
функций конвертации в строковое представление а так же внтутритиповых операторов сравнения (больше и равно), сложения, 
вычитания, умножения и деления.
Поддерживается регистрация элементов типов-перечислений.

\section using_library Использование библиотеки AnandamideAPI.

\subsection libraries Создание библиотеки пользовательских типов и блоков.

Для создания произвольной логики на языке блочного скрипта используются различные блоки. Стандартная библиотека блоков
содержит основные функции для создания циклов, ветвлений и некоторых операций. Для расширения набора блоков, из которых 
состоят скрипты имеется механизм внешних библиотек. Внешние библиотеки создаются в виде динамических библиотек *.dll.
Для создания библиотеки необходимо настроить проект на сборку динамической библиотеки (*.dll). Для того, чтобы такая
динамическая библиотека могла подключаться к AnandamideAPI, должны соблюдаться следующие условия:
1. Внешнаяя билблиотека должна использовать AnandamideAPI
2. В библиотеке должна быть объявлена функция регистрации библиотеки в виде:
	\code {.cpp}
	extern "C" __declspec(dllexport) void anandamideDefineLibrary(Anandamide::Library *library);
	\endcode

Внутри функции регистрации библиотеки должно происходить заполнение полей объекта library.<br>
Для того, чтобы объвить имя библиотеки, необходимо выполнить следующее:

	\code {.cpp}
	void anandamideDefineLibrary(Anandamide::Library *library) {
		// задаем имя "Sample"
		library->setName("Sample");
		...
	}
	\endcode

\subsection type_libraries Регистрация библиотечных типов.

Для того, чтобы пользовательский тип был загеристрирован для использования в библотеке, необходимо выполнить следующие 
условия:

1. Необходимо присвоить пользовательскому типу уникальный идентификатор, который позволит однозначно идентифицировать
тип. Обязательно необходимо делать это в заголовочном файле, после того, как необходимый тип был объявлен.<br>
	\code {.cpp}
	// Например, имеем следующий тип данных:
	class UBER_API UberType {
	public:
		virtual ~UberType();
		
		virtual int getValue() const;
				
	};
	
	// Ниже в заголовочном файле необходимо зарегистрировать идентификатор типа:
	DEFINE_TYPEID(UberType , 109901)
	
	// Таким образом, требуемый тип будет зарегистрирован
	\endcode

2. Нужно зарегистрировать данный тип и присвоить ему визуальное оформление (цвет и пиктограмму).
Для этого внутри функции регистрации библиотеки необходимо сделать слудующее:
	\code {.cpp}
	void anandamideDefineLibrary(Anandamide::Library *library) {
		...
		library->addType <UberType> (0.7f, 0.5f, 0.7f, ADD_IMG(":/types/types/variable.png"));
		...
	}
	\endcode

Для регистрации типов-перечислений используется следующий синтаксис:


	\code {.cpp}
	// объявление типа перечисления
	enum CompareOperation {
		IF_EQUAL,
		IF_NOTEQUAL,
		IF_GREATER,
		IF_GEQUAL,
		IF_LESS,
		IF_LEQUAL,
	};
	
	// начало регистрации типа перечисления
	ENUM_BEGIN(CompareOperation)
	
		// регистрация элементов типа перечисления	
		ENUM_ITEM_NAMED(IF_EQUAL,		"==")
		ENUM_ITEM_NAMED(IF_NOTEQUAL,	"!=")
		ENUM_ITEM_NAMED(IF_GREATER,		">")
		ENUM_ITEM_NAMED(IF_GEQUAL,		">=")
		ENUM_ITEM_NAMED(IF_LESS,		"<")
		ENUM_ITEM_NAMED(IF_LEQUAL,		"<=")
	
	// конец регистрации типа перечисления и присвоение идентификатора
	ENUM_END(CompareOperation, 550000)
	\endcode

Если название элемента перечисления должно совпадать с символом элемента перечисления, для регистрации элемента 
можно воспользоваться упрощенной формой:

	\code {.cpp}
	// начало регистрации типа перечисления
	ENUM_BEGIN(CompareOperation)
	
		// регистрация элементов типа перечисления	
		ENUM_ITEM(IF_EQUAL)
		ENUM_ITEM(IF_NOTEQUAL)
		ENUM_ITEM(IF_GREATER)
		ENUM_ITEM(IF_GEQUAL)
		ENUM_ITEM(IF_LESS)
		ENUM_ITEM(IF_LEQUAL)
	
	// конец регистрации типа перечисления и присвоение идентификатора
	ENUM_END(CompareOperation, 550000)
	\endcode

\subsection block_libraries Регистрация библиотечных блоков.

Библиотеки могут содержать произвольное количество блоков, которые дополнительно могут быть классифицированны по группам
(kinds). Есть три основных способа создания новых блоков - создание блоков из обычных функций, создание блоков из 
членов класса и создание произвольных блоков.

\subsection function_lib_blocks Создание блоков из функций.
AnandamideAPI содержит механизм автоматического создания новых блоков из обычных функций с использованием всего одной строчки кода.
Для создания такого блока, необходимо сделать следующее:
1. Создать функцию, на основе которой требуется создать блок:
	\code {.cpp}
		int arraySize(VariableArray array) {
			return array->count();
		}
	\endcode

2. Убедиться, что типы данных, которые использует функция, уже зарегистрированы в какой-либо библиотеке.
	\code {.cpp}
	typedef Array <Variable> VariableArrayData;
	DEFINE_TYPEID(VariableArray	, 330022)
	\endcode

3. Зарегистрировать функциональный блок в библиотеке.
	\code {.cpp}
	void anandamideDefineLibrary(Anandamide::Library *library) {
		...
		library->addFunction("Std/Array(kind)", "arraySize(Id)", "arraySize(BlockHeader)", &arraySizeFuncPtr, "size(return_value_name)", {"array(input_parameter_names)"});
		...
	}
	\endcode

\subsection member_lib_blocks Создание блоков из членов класса.

Функция уже реализована, и вы можете обраться к разработчику, чтобы получить дополнительную информацию.

\subsection user_lib_blocks Создание блоков с произвольной логикой.

Если необходимо создать блок с такой логикой работы, какую нельзя реализовать с помощью функциональных блоков,
необходимо выполнить следующие шаги:

1. Объявить класс-наследник от Neurone
	\code {.cpp}
	class If : public Neurone {
		...
	};
	\endcode
2. Перегрузить статческую функцию Anandamide::Neurone::define() и заполнить стуктуру Anandamide::NeuroneDef. Это необходимо для того, чтобы
	в редакторе блоков можно было получить полную информацию о блоке без фактического создания работающего блока.
	Иногда требуется непосредственное создание блока в редакторе без замещения его блоком-пустышкой. Это необходимо
	для создания блоков, вид которых зависит от параметров.
	\code {.cpp}
	static void define(NeuroneDef *def) {
		
		// задать группу-классификацию для блока
		def->setKind("FlowControl");
		
		// установка флага создания настоящего блока вместо блока-пустышки в редакторе скриптов
		def->setCreateDummy(false);
		
		// добавление скрытый параметр, который отвечает за операцию сравнения
		def->addParameter <CompareOperation> ("op", "==");
		
		// добавление входных параметров a, b
		def->addInput <Variable> ("a", "0");
		def->addInput <Variable> ("b", "0");
		
		// добавление событий ветвления
		def->addEvent("then");
		def->addEvent("else");
		
		// добавление действия запуска операции сравнения
		def->addAction("check");
	}
	\endcode
3. Перегрузить виртуальные функции и реализовать логику работы блока 
	(например, Anandamide::Neurone::onInit(), Anandamide::Neurone::hasCaption(), Anandamide::Neurone::onGetCaption())
	\code {.cpp}
	// Функция, которая автоматически вызывается при создании нового экземпляра блока.
	// К моменту вызова этой функции все компоненты блока, описанные в NeuroneDef будут автоматичеки созданы
	void onInit(Libraries *libraries) override {

		// Получение параметра блока
		p_op = getParameter("op");
		
		// Получение входных параметров блока
		i_a = getInput("a");
		i_b = getInput("b");

		// Получение событий блока
		e_then = getEvent("then");
		e_else = getEvent("else");

		// Связь действия и функции, которая вызвается при активации этого действия
		getAction("check")->setAction(Common::Action::create(this, &If::in));
	}
	
	// Функция, которая автоматически вызвается для определения, имеет ли текущий блок вторую строку заголовка.
	bool hasCaption() override {
		return true;
	}
	
	// Функция, которая автоматически вызывается для получения второй строки заголовка блока.
	Str onGetCaption() override {
		return format("a %s b", p_op->getValue().getStr());
	}
	
	// реализация логики действия "check"
	void in() {
		CompareOperation op = VariableToType <CompareOperation> (p_op->getValue()).value;
		
		if (check(i_a->getValue(), i_b->getValue(), op)) {
			e_then->run();
		} else {
			e_else->run();
		}
	}
	\endcode
4. Зарегистрировать класс блока в библиотеке
	\code {.cpp}
	void anandamideDefineLibrary(Anandamide::Library *library) {
		...
		library->addTemplate <If> ("If");
		...
	}
	\endcode
	
\subsection variables Работа с универсальным типом данных Variable.

Для харанения и передачи данных в библиотеке AnandamideAPI вводится тип данных Variable, который способен хранить
данные любого типа. Для базовых типов данных (int, float, double, const char *, Enum, etc) возможна атоматическая 
конвертация между этими типами. <br>

Для того, чтобы в рамках реализации произвольных блоков работать с различными типами данных, необходимо использовать
шаблонные классы, обеспечивающие конвертацию Variable в различные типы (Anandamide::VariableToType):

	\code {.cpp}
	class SomeBlock : public Neurone {
		...
		void init() {
			int some_param_int = VariableToType <int> (getParameter(0).getValue()).value;
			Str some_param_string = VariableToType <Str> (getParameter(1).getValue()).value;
			double some_param_double = VariableToType <double> (getParameter(2).getValue()).value;
		}
		...
	};
	\endcode

Для конвертации различных типов в Variable необходимо пользоваться шаблонными классами Anandamide::TypeToVariable:
	\code {.cpp}
	class GetDoubleResult : public Neurone {
		
		...
		//
		void in() {
			
			double a = VariableToType <double> (getInput(0).getValue()).value;
			double b = VariableToType <double> (getInput(1).getValue()).value;
			double c = VariableToType <double> (getInput(2).getValue()).value;
			
			getOutput(0).setValue(TypeToVariable(a + b * c).value);
			
			out->run();
		}
		...
	};
	\endcode

*/
