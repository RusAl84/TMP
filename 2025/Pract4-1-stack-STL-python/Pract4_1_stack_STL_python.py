class myStack:
    def __init__(self):
        self._st = []

    def push(self, x: int) -> None:
        self._st.append(x)

    def pop(self) -> None:
        self._st.pop()

    def peek(self) -> int:
        return self._st[-1]

    def isEmpty(self) -> bool:
        return len(self._st) == 0

    def size(self) -> int:
        return len(self._st)

class Adapter4StackSTL(myStack):

    def display(self) -> None:
        x=0
        st = Adapter4StackSTL()
        print("Display")
        while (not self.isEmpty()):
            x=self.peek()
            self.pop()
            print(x)
            st.push(x)
        while (not st.isEmpty()):
            x=st.peek()
            st.pop()
            self.push(x)
        print("________")

    def getElement(self, ind: int) -> int:
        x=-1
        if  0 <= ind < self.size():
            st = Adapter4StackSTL()
            num=0
            while (not self.isEmpty()):
                x=self.peek()
                self.pop()
                st.push(x)
                if num==ind:
                    break
                num+=1
            while (not st.isEmpty()):
                tmp_x=st.peek()
                st.pop()
                self.push(tmp_x)
            return x
        return x

    def setElement(self, ind: int, element: int) -> None:
        x=-1
        if  0 <= ind < self.size():
            st = Adapter4StackSTL()
            num=0
            while (not self.isEmpty()):
                x=self.peek()
                self.pop()    
                if num==ind:
                    break
                st.push(x)
                num+=1
            st.push(element)
            while (not st.isEmpty()):
                tmp_x=st.peek()
                st.pop()
                self.push(tmp_x)
            return x
        return x



if __name__ == "__main__":
    st = Adapter4StackSTL()

    st.push(100)
    st.push(200)
    st.push(300)
    st.push(400)
    st.push(700)
    st.push(700)
    st.push(777)

    print()
    st.display()
    st.display()
    print(" st.getElement(0) =", st.getElement(0))
    print(" st.getElement(3) =", st.getElement(3))
    print(" st.getElement(6) =", st.getElement(6))
    print(" st.getElement(7) =", st.getElement(7))

    st.setElement(3, 888)
    st.display()
