
class myStack:
    def __init__(self):
        self._items = []

    def push(self, item):
        """Добавить элемент на вершину стека."""
        self._items.append(item)

    def pop(self):
        """Снять и вернуть элемент с вершины стека."""
        if self.is_empty():
            raise IndexError("pop from empty stack")
        return self._items.pop()

    def peek(self):
        """Посмотреть верхний элемент, не снимая его."""
        if self.is_empty():
            raise IndexError("peek from empty stack")
        return self._items[-1]

    def is_empty(self) -> bool:
        """Проверить, пуст ли стек."""
        return len(self._items) == 0

    def size(self) -> int:
        """Количество элементов в стеке."""
        return len(self._items)

    def clear(self):
        """Очистить стек."""
        self._items.clear()

    def __len__(self):
        return len(self._items)

    def __bool__(self):
        return not self.is_empty()

    def __repr__(self):
        return f"myStack({self._items})"

    def display(self):
        tempStack = myStack()
        print("Display myStack: ")
        while (not self.is_empty()):
            x = self.pop()
            print(x)
            tempStack.push(x)
        while (not tempStack.is_empty()):
            x = tempStack.pop()
            self.push(x)
        print("________________________")

class myStackAdapter(myStack):


    def getElement(self, index: int):
        """Вернуть элемент по индексу, не снимая его со стека."""
        if 0<=index <self.size():
            tempStack = myStack()
            ind=0
            element=0
            while (not self.is_empty()):
                element = self.pop()
                tempStack.push(element)
                if ind == index:
                    break;
                ind+=1
            while (not tempStack.is_empty()):
                tmpElement = tempStack.pop()
                self.push(tmpElement)
            return element


    def setElement(self, index: int, element) -> None:
        """Заменить элемент по индексу на новое значение."""
        if 0<=index <self.size():
            tempStack = myStack()
            ind=0
            while (not self.is_empty()):
                tmpElement = self.pop()
                if ind == index:
                    break;
                tempStack.push(tmpElement)
                ind+=1
            tempStack.push(element)
            while (not tempStack.is_empty()):
                tmpElement = tempStack.pop()
                self.push(tmpElement)



# Пример использования
if __name__ == "__main__":
    s = myStackAdapter()
    s.push(1)
    s.push(2)
    s.push(3)

    # print(s)          # myStack([1, 2, 3])
    # print(s.peek())   # 3
    # print(s.pop())    # 3
    # print(s.pop())    # 2
    # print(s.size())   # 1
    # print(s.is_empty())  # False
    # s.clear()
    # print(s.is_empty())  # True

    # print(s)                 # myStackAdapter([10, 20, 30])
    s.display()
    print(s.getElement(0))   # 10  (нижний)
    print(s.getElement(1))   # 30  (верхний)
    print(s.getElement(4))  # 30  (верхний)

    s.setElement(0, 0)
    s.setElement(1, 777)
    s.setElement(2, 222)
    s.setElement(4, 888)
    s.display()
