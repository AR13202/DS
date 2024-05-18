template <typename T>
class bst{
    public:
    T data;
    bst* left;
    bst* right;
    bst(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~bst(){
        delete left;
        delete right;
    }
};