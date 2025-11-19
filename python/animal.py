class Animal:
    def __init__(self,name,color):
        self._name = name
        self._color = color
    
    def mover(self):
        print(f'{self._name} andou...')
