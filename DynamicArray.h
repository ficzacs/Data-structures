template<typename T>
class DynamicArray{
public:
    Vector(){
        Realloc(2);
    }
private:
    void Realloc(size_t newCapacity){

        T* newBlock = new T[newCapacity];

        for(size_t i = 0; i < m_Size; i++){
            newBlock[i] = m_Data;
        }

        delete[] m_data;
        m_Data = newBlock;
        m_Capacity = newCapacity;

    }


    T* mdata = nullptr;
        
    size_t m_Size = 0;
    size_t m_Capacity = 0;
};