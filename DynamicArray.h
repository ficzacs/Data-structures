template<typename T> class DynamicArray{
public:
    DynamicArray(){
        Realloc(2);
    }

    ~DynamicArray(){
        Clear();
        ::operator delete(m_Data, m_Capacity * sizeof(T));
    }

    void PushBack(const T& val){
        if(m_Size >= m_Capacity){
            Realloc(m_Capacity + m_Capacity / 2);
        }
        m_Data[m_Size++] = val;
    }

    void PopBack(){
         if(m_Size > 0){
            m_Size--;
            m_Data[m_Size].~T();
         }
    }

    void Clear(){
        for(size_t i = 0; i < m_Size; i++){
            m_Data[i].~T();
        }
        m_Size = 0;
    }

    void printArray(){
        for(size_t i = 0; i< m_Size; i++){
            std::cout << m_Data[i] << " ";
        }
        std::cout << std::endl;
    }

    size_t Size() const {return m_Size;}

    const T& operator[](size_t index) const{
        return m_Data[index];
    }

    T& operator[](size_t index){
        return m_Data[index];
    }

private:
    void Realloc(size_t newCapacity){

        T* newBlock = (T*)::operator new(newCapacity * sizeof(T));

        if(newCapacity < m_Size){
            m_Size = newCapacity;
        }

        for(size_t i = 0; i < m_Size; i++){
            newBlock[i] = std::move(m_Data[i]);
        }

        for(size_t i = 0; i < m_Size; i++){
            m_Data[i].~T();
        } 

        ::operator delete(m_Data, m_Capacity * sizeof(T));
        m_Data = newBlock;  
        m_Capacity = newCapacity;
    }
    T* m_Data = nullptr;
        
    size_t m_Size = 0;
    size_t m_Capacity = 0;
};