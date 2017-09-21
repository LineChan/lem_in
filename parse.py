import settings as s

def room(inputList) :
    inputList[:] = (line for line in inputList if (line != '\n'))
    print('intputList : %s' % (inputList))

