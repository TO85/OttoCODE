#file: ./src/hosts.pri
message(----------------In ./src/hosts.pri)

# EIRC_QMAKE_HOST=eagle
message(EIRC_QMAKE_HOST = $$(EIRC_QMAKE_HOST))
EIRC_HOST = $$(EIRC_QMAKE_HOST) # Convert system environment variable to qmake internal variable

include(./hosts/$${EIRC_HOST}.pri)

