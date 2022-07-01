using namespace std;

namespace Contoso
{
    class IntArray
    {
    private:
        const int growth_factor = 2;
        int *arr;
        // default size is 10
        int size = 10;
        int used = 0;

        void IncreaseSize()
        {
            int new_size = size * growth_factor;
            ChangeSize(new_size);        
        }

        void DecreaseSize()
        {
            int new_size = size / growth_factor;
            ChangeSize(new_size);
        }

        void ChangeSize(int new_size)
        {
            int *new_arr = new int[new_size];
            
            for (int i = 0; i <= used; i++)
            {
                new_arr[i] = arr[i];
            }

            int *old_arr = arr;
            arr = new_arr;
            delete[] old_arr;

            size = new_size;   
        }

    public:
        IntArray(int initialSize)
        {
            arr = new int[initialSize];
            size = initialSize;
        }
        IntArray()
        {
            arr = new int[size];
        }
        int GetSize()
        {
            return size;
        }
        int GetCount()
        {
            return used;
        }
        //O(N)
        int * GetAll()
        {
            return arr;
        }
        //O(1) = O(N)
        void Add(int data)
        {
            if (used < size)
            {
                arr[used] = data;
            }
            else
            {
                IncreaseSize();
                arr[used] = data;
            }

            used++;
        }
        void DeleteAt(int index)
        {
            arr[index] = 0;
            used--;
            for (int i = index; i < size; i++)
            {
                if (arr[i + 1] != 0)
                {
                    arr[i] = arr[i + 1];
                }
            }
            
            if (used <= size / growth_factor)
            {
                DecreaseSize();
            }
        }
    };
} // namespace Contoso