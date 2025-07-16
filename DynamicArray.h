template<typename T> class DynamicArray{
public:
    DynamicArray(){
        Realloc(2);
    }

    void PushBack(const T& val){
        
        if(m_Size >= m_Capacity){
            Realloc(m_Capacity + m_Capacity / 2);
        }

        m_Data[m_Size++] = val;
    }

    size_t Size() const {return m_Size;}


    const T& operator[](size_t index) const{
        return m_Data[index];
    }

private:
    void Realloc(size_t newCapacity){

        T* newBlock = new T[newCapacity];

        for(size_t i = 0; i < m_Size; i++){
            newBlock[i] = m_Data[i];
        }

        delete[] m_Data;
        m_Data = newBlock;  
        m_Capacity = newCapacity;

    }


    T* m_Data = nullptr;
        
    size_t m_Size = 0;
    size_t m_Capacity = 0;
};