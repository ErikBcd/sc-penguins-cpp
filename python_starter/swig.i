%module(directors="1") SC_2022_PY
%{
    #define SWIG_FILE_WITH_INIT
    #include "../sc_library/include/client/client.h"
    #include "../sc_library/include/communication/message_handler.h"
    #include "../sc_library/include/communication/tcp_connection.h"
    #include "../sc_library/include/communication/xml_string_writer.h"
    #include "../sc_library/include/game/util/coordinates.h"
    #include "../sc_library/include/game/board.h"
    #include "../sc_library/include/game/gameState.h"
    #include "../sc_library/include/game/move.h"
    #include "../sc_library/include/game/result.h"
    #include "../sc_library/include/logic/logic.h"

%}

%feature("director") Logic::Logic;

%include <argcargv.i>
%apply (int ARGC, char **ARGV) { (int argc, char *argv[]) }
void Client::Game_Client::Start(int argc, char *argv[]);

%include <std_string.i>
%include <std_vector.i>
%include <std_array.i>
%include "typemaps.i"
%include "../sc_library/include/client/client.h"
%include "../sc_library/include/communication/message_handler.h"
%include "../sc_library/include/communication/tcp_connection.h"
%include "../sc_library/include/communication/xml_string_writer.h"
%include "../sc_library/include/game/util/coordinates.h"
%include "../sc_library/include/game/board.h"
%include "../sc_library/include/game/gameState.h"
%include "../sc_library/include/game/move.h"
%include "../sc_library/include/game/result.h"
%include "../sc_library/include/logic/logic.h"

%template(Move_Vector) std::vector<Game::Move>;