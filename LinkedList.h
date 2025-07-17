template<typename T> class Node{
private:
    T val;
    Node* next;

public:
    Node() : val(T()), next(nullptr){};
    Node(T val) : val(val), next(nullptr){};
    Node(T val, Node* next) : val(val), next(next){};

    T getVal() const {return val;}
    Node<T>* getNext() const {return next;}
    void setNext(Node<T>* next){this->next = next;}
};

template<typename T> class LinkedList{
private:
    Node<T>* head;

public:
    
    LinkedList() : head(nullptr){};
    LinkedList(Node<T>* head) : head(head){};

    Node<T>* nodeExists(T num) const{
        Node<T>* ptr = head;

        while(ptr != nullptr){
            if(ptr.getVal() == num){
                return ptr;
            }
            ptr = ptr.next;
        }
        return nullptr;
    }

    void AppendNode(T val){
        Node<T>* newNode = new Node<T>(val);

        if(head == nullptr){
            head = newNode;
        } else {
            Node<T>* tmp = head;
            while(tmp->getNext() != nullptr){
                tmp = tmp->getNext();
            }
            tmp->setNext(newNode);
        }
    }

    void PrintList(){
        Node<T>* tmp = head;

        while(tmp != NULL){
            std::cout << tmp->getVal() << " ";
            tmp = tmp->getNext();
        }
        std::cout << std::endl;
    }
};