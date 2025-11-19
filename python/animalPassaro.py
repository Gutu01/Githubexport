from animal import Animal

class Passaro(Animal):
    def __init__(self, _name, _color, tipo):
        super().__init__(_name, _color)
        self.tipo = tipo
    
    def mover(self):
        print(f"{self._name} voou...")