#https://www.geeksforgeeks.org/dsa/introduction-to-stack-data-structure-and-algorithm-tutorials/
#https://www.geeksforgeeks.org/dsa/implement-a-stack-using-singly-linked-list/

# Node structure
class Node:
    def __init__(self, x):
        self.data = x
        self.next = None


# Stack class
class myStack:
    def __init__(self):
        self.top = None

    def push(self, x):
        temp = Node(x)
        temp.next = self.top
        self.top = temp

    def pop(self):
        if self.top is None:
            print("Stack Underflow")
            return -1
        temp = self.top
        self.top = self.top.next
        val = temp.data
        del temp
        return val

    def peek(self):
        if self.top is None:
            print("Stack is Empty")
            return -1
        return self.top.data

    def isEmpty(self):
        return self.top is None

    # size of stack
    def size(self):
        count = 0
        next=self.top.next 
        while not next == None:
            count+=1
            next = next.next
        return count+1

    def display(self):
        tmpSt = myStack()
        print("display____")
        while not self.isEmpty():
            x = self.peek();
            self.pop()
            tmpSt.push(x)
        while not tmpSt.isEmpty():
            x = tmpSt.peek();
            tmpSt.pop()
            self.push(x)
            print(x)
        print("____")

class myStackAdapter(myStack):

    def getElement(self, index):
        element =-1 
        size = self.size()
        if 0<=index<size:
            tmpSt = myStackAdapter()
            num=0
            while not self.isEmpty():
                element = self.peek();
                self.pop()
                tmpSt.push(element)
                if num==index:
                    break
                num+=1
            while not tmpSt.isEmpty():
                y = tmpSt.peek();
                tmpSt.pop()
                self.push(y)
        return element

    def setElement(self, index, element):
        size = self.size()
        if 0<=index<size:
            tmpSt = myStackAdapter()
            num=0
            while not self.isEmpty():
                x = self.peek();
                self.pop()
                if num==index:
                    break
                num+=1
                tmpSt.push(x)
            tmpSt.push(element)
            while not tmpSt.isEmpty():
                y = tmpSt.peek();
                tmpSt.pop()
                self.push(y)
        return element

if __name__ == "__main__":
    st = myStackAdapter()

    st.push(1000)
    st.push(2000)
    st.push(3000)
    st.push(4000)
    st.push(5000)
    st.display()

    print("getElement(0)",st.getElement(0))
    print("getElement(1)",st.getElement(1))
    print("getElement(2)",st.getElement(2))
    print("getElement(3)",st.getElement(3))
    print("getElement(4)",st.getElement(4))

    st.setElement(4,777)
    st.display()
