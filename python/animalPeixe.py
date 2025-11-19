from animal import Animal

class Peixe(Animal):
    def __init__(self, _name, _color, peso):
        super().__init__(_name, _color)
        self.peso = peso

    def mover(self):
        print(f"{self._name} nadou...")