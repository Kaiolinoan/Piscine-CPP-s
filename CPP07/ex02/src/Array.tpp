
template <typename T>
Array<T>::Array() : arr(NULL), len(0) {};

template <typename T>
Array<T>::~Array()
{
    delete [] this->arr;
}

template <typename T>
Array<T>::Array(const unsigned int &n) 
{
    this->arr = new T[n]();
    this->len = n;
}

template <typename T>
Array<T>::Array(const Array<T>& other)
{
    this->len = other.len;
    if (other.arr && other.len > 0)
    {
        T* new_ptr = new T[other.len];
        for (unsigned int i = 0; i < other.len; i++)
            new_ptr[i] = other.arr[i];
        this->arr = new_ptr;
    }
    else
        this->arr = NULL;
}

template <typename T>
Array<T>&   Array<T>::operator=(const Array<T>& other)
{
    if (this != &other)
    {
        this->len = other.len;
        if (other.arr && other.len > 0)
        {
            T* new_ptr = new T[other.len];
            for (unsigned int i = 0; i < other.len; i++)
                new_ptr[i] = other.arr[i];
            delete [] this->arr;
            this->arr = new_ptr;
        }
        else
        {
            delete [] this->arr;
            this->arr = NULL;
        }
    }
    return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int i)
{
    if (i >= this->len)
        throw InvalidIndex();
    return (this->arr[i]);
}

template <typename T>
const T& Array<T>::operator[](unsigned int i) const
{
    if (i >= this->len)
        throw InvalidIndex();
    return (this->arr[i]);
}

template <typename T>
unsigned int Array<T>::size() const
{
    return (this->len);
}

