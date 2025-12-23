
template <typename T> struct Node {
    Node *next;
    T data;
    Node(T data, Node *next = nullptr) : data(data), next(next) {}
};

template <typename T> class List {
  private:
    Node<T> *head;

  public:
    List();
    ~List();
    bool is_empty();
    void append(T data);
    void add_first(T data);
    void insert_after(T data, Node<T> *current);
    void remove(Node<T> *current);
    // void print();
    Node<T> *find(T data);
};
