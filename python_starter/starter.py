from SC_PY_WRAPPER import Logic, Client
from custom_logic import MyLogic

logic = MyLogic()
client = Client(logic)

client.start(3, 'none 127.0.0.1 13050')