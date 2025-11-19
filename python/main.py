from animal import Animal
from animalPeixe import Peixe
from animalPassaro import Passaro

if __name__ == "__main__":
    a1 = Animal("Lunha", "Champanhe")
    a1.mover()

    a2 = Animal("Sol", "Preto")
    a2.mover()

    p1 = Peixe("Nemo", "Listrado", "0.5")
    p1.mover()

    p2 = Peixe("Dori", "Azul", "0.1")
    p2.mover()

    g1 = Passaro("PiuPiu", "Amarelinho", "Avestrus")
    g1.mover()