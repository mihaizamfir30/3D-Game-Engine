#pragma once

#include <glm/glm.hpp>
#include <include/gl.h>

#include <iostream>

//using namespace std;

/*
Keypad0	Numeric keypad 0.
Keypad1	Numeric keypad 1.
Keypad2	Numeric keypad 2.
Keypad3	Numeric keypad 3.
Keypad4	Numeric keypad 4.
Keypad5	Numeric keypad 5.
Keypad6	Numeric keypad 6.
Keypad7	Numeric keypad 7.
Keypad8	Numeric keypad 8.
Keypad9	Numeric keypad 9.
*/

/*

None	Not assigned (never returned as the result of a keystroke).
Backspace	The backspace key.
Delete	The forward delete key.
Tab	The tab key.
Clear	The Clear key.
Return	Return key.
Pause	Pause on PC machines.
Escape	Escape key.
Space	Space key.
Keypad0	Numeric keypad 0.
Keypad1	Numeric keypad 1.
Keypad2	Numeric keypad 2.
Keypad3	Numeric keypad 3.
Keypad4	Numeric keypad 4.
Keypad5	Numeric keypad 5.
Keypad6	Numeric keypad 6.
Keypad7	Numeric keypad 7.
Keypad8	Numeric keypad 8.
Keypad9	Numeric keypad 9.
KeypadPeriod	Numeric keypad '.'.
KeypadDivide	Numeric keypad '/'.
KeypadMultiply	Numeric keypad '*'.
KeypadMinus	Numeric keypad '-'.
KeypadPlus	Numeric keypad '+'.
KeypadEnter	Numeric keypad Enter.
KeypadEquals	Numeric keypad '='.
UpArrow	Up arrow key.
DownArrow	Down arrow key.
RightArrow	Right arrow key.
LeftArrow	Left arrow key.
Insert	Insert key key.
Home	Home key.
End	End key.
PageUp	Page up.
PageDown	Page down.
F1	F1 function key.
F2	F2 function key.
F3	F3 function key.
F4	F4 function key.
F5	F5 function key.
F6	F6 function key.
F7	F7 function key.
F8	F8 function key.
F9	F9 function key.
F10	F10 function key.
F11	F11 function key.
F12	F12 function key.
F13	F13 function key.
F14	F14 function key.
F15	F15 function key.
Alpha0	The '0' key on the top of the alphanumeric keyboard.
Alpha1	The '1' key on the top of the alphanumeric keyboard.
Alpha2	The '2' key on the top of the alphanumeric keyboard.
Alpha3	The '3' key on the top of the alphanumeric keyboard.
Alpha4	The '4' key on the top of the alphanumeric keyboard.
Alpha5	The '5' key on the top of the alphanumeric keyboard.
Alpha6	The '6' key on the top of the alphanumeric keyboard.
Alpha7	The '7' key on the top of the alphanumeric keyboard.
Alpha8	The '8' key on the top of the alphanumeric keyboard.
Alpha9	The '9' key on the top of the alphanumeric keyboard.
Exclaim	Exclamation mark key '!'.
DoubleQuote	Double quote key '"'.
Hash	Hash key '#'.
Dollar	Dollar sign key '$'.
Percent	Percent '%' key.
Ampersand	Ampersand key '&'.
Quote	Quote key '.
LeftParen	Left Parenthesis key '('.
RightParen	Right Parenthesis key ')'.
Asterisk	Asterisk key '*'.
Plus	Plus key '+'.
Comma	Comma ',' key.
Minus	Minus '-' key.
Period	Period '.' key.
Slash	Slash '/' key.
Colon	Colon ':' key.
Semicolon	Semicolon ';' key.
Less	Less than '<' key.
Equals	Equals '=' key.
Greater	Greater than '>' key.
Question	Question mark '?' key.
At	At key '@'.
LeftBracket	Left square bracket key '['.
Backslash	Backslash key '\'.
RightBracket	Right square bracket key ']'.
Caret	Caret key '^'.
Underscore	Underscore '_' key.
BackQuote	Back quote key '`'.
A	'a' key.
B	'b' key.
C	'c' key.
D	'd' key.
E	'e' key.
F	'f' key.
G	'g' key.
H	'h' key.
I	'i' key.
J	'j' key.
K	'k' key.
L	'l' key.
M	'm' key.
N	'n' key.
O	'o' key.
P	'p' key.
Q	'q' key.
R	'r' key.
S	's' key.
T	't' key.
U	'u' key.
V	'v' key.
W	'w' key.
X	'x' key.
Y	'y' key.
Z	'z' key.
LeftCurlyBracket	Left curly bracket key '{'.
Pipe	Pipe '|' key.
RightCurlyBracket	Right curly bracket key '}'.
Tilde	Tilde '~' key.
Numlock	Numlock key.
CapsLock	Capslock key.
ScrollLock	Scroll lock key.
RightShift	Right shift key.
LeftShift	Left shift key.
RightControl	Right Control key.
LeftControl	Left Control key.
RightAlt	Right Alt key.
LeftAlt	Left Alt key.
LeftCommand	Left Command key.
LeftApple	Left Command key.
LeftWindows	Left Windows key.
RightCommand	Right Command key.
RightApple	Right Command key.
RightWindows	Right Windows key.
AltGr	Alt Gr key.
Help	Help key.
Print	Print key.
SysReq	Sys Req key.
Break	Break key.
Menu	Menu key.
Mouse0	The Left (or primary) mouse button.
Mouse1	Right mouse button (or secondary mouse button).
Mouse2	Middle mouse button (or third button).
Mouse3	Additional (fourth) mouse button.
Mouse4	Additional (fifth) mouse button.
Mouse5	Additional (or sixth) mouse button.
Mouse6	Additional (or seventh) mouse button.
*/

enum KeyCode {
	Backspace = 8, Delete = 127, Tab = 9, Return = 13, Esc = 27, Space = 32,
	Keypad0 = 321, Keypad1, Keypad2, Keypad3, Keypad4, Keypad5, Keypad6, Keypad7, Keypad8, Keypad9,
	Right = 262, Left, Down, Up,
	Alpha0 = 48, Alpha1, Alpha2, Alpha3, Alpha4, Alpha5, Alpha6, Alpha7, Alpha8, Alpha9,
	A = 65, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z
};

class Input
{
	
	public:
		static void OnKeyPressed(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void MouseCallback(GLFWwindow* window, double xpos, double ypos);
		static void ScrollCallback(GLFWwindow* window, double xOffset, double yOffset);

		static bool GetKey(KeyCode key);

		static void Update();

		static glm::vec2 GetMousePosition();
		static glm::vec2 GetMouseScroll();

	private:

		static bool GetKeyUp(KeyCode key);
		static bool GetKeyDown(KeyCode key);

		static int keyState[500];

		static glm::vec2 mousePosition;
		static glm::vec2 mouseScroll;

};
