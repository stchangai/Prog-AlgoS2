#include <QApplication>
#include <QString>
#include <time.h>
#include <stdio.h>
#include <string>

#include <tp5.h>

MainWindow* w = nullptr;
using std::size_t;
using std::string;


std::vector<string> TP5::names(
{
    "Yolo", "Anastasiya", "Clement", "Sirine", "Julien", "Sacha", "Leo", "Margot",
    "JoLeClodo", "Anais", "Jolan", "Marie", "Cindy", "Flavien", "Tanguy", "Audrey",
    "Mr.PeanutButter", "Bojack", "Mugiwara", "Sully", "Solem",
    "Leo", "Nils", "Vincent", "Paul", "Zoe", "Julien", "Matteo",
    "Fanny", "Jeanne", "Elo"
});

unsigned long int hash(string key)
{
    // return an unique hash id from key
    unsigned long int hash_value = 0;
    for(int i=0;i<key.length;i++){
        hash_value += (int)key[i] * std::pow(127,(float)key.length-i);
    }
    return hash_value;
    //return 0;
}

struct MapNode : public BinaryTree
{

    string key;
    unsigned long int key_hash;

    int value;

    MapNode* left;
    MapNode* right;

    MapNode(string key, int value) : BinaryTree (value)
    {
        this->key = key;
        this->value = value;
        this->key_hash = hash(key);

        this->left = this->right = nullptr;
    }

    /**
     * @brief insertNode insert a new node according to the key hash
     * @param node
     */
    void insertNode(MapNode* node)
    {
        if(this->key_hash >= node->key_hash){
            if(this->left == NULL){
                this->left = node;
            }
            else{
                this->left->insertNode(node);
            }
        }

        if(this->key_hash < node->key_hash){
            if(this->right == NULL){
                this->right = node;
            }
            else{
                this->right->insertNode(node);
            }
        }
        
    }

    void insertNode(string key, int value)
    {
        this->insertNode(new MapNode(key, value));
    }

    virtual ~MapNode() {}
    QString toString() const override {return QString("%1:\n%2").arg(QString::fromStdString(key)).arg(value);}
    Node* get_left_child() const {return left;}
    Node* get_right_child() const {return right;}
};

struct Map
{
    Map() {this->key = key;
        this->value = value;
        this->key_hash = hash(key);

        this->left = this->right = nullptr;
    }
    /*and insert it to the map
     * @param key
     * @param value
     */
     void insert(string key, int value)
    {
        MapNode *newNode=new MapNode(key, value);
        newNode->key=key;
        newNode->value=value;
        newNode->key_hash=hash(key);
        if(this->root== NULL){
            this->root= newNode;
        }else{
            this->root->insertNode(newNode);
        }
    }

    /**
     * @brief get return the value of the node corresponding to key
     * @param key
     * @return
     */
    void get(string key, int value)
    {
        MapNode *newNode=new MapNode(key, value);
        newNode->key=key;
        newNode->value=value;
        newNode->key_hash=hash(key);
        if(this->root== NULL){
            this->root= newNode;
        }else{
            this->root->insertNode(newNode);
        }

        
    }

    MapNode* root;
};


int main(int argc, char *argv[])
{
    srand(time(NULL));
	Map map;

    map.insert("Yolo", 20);
    for (std::string& name : TP5::names)
    {
        if (rand() % 3 == 0)
        {
            map.insert(name, rand() % 21);
        }
    }

    qDebug("map[\"Margot\"]=%d\n", map.get("Margot"));
    qDebug("map[\"Jolan\"]=%d\n", map.get("Jolan"));
    qDebug("map[\"Lucas\"]=%d\n", map.get("Lucas"));
    qDebug("map[\"Clemence\"]=%d\n", map.get("Clemence"));
    qDebug("map[\"Yolo\"]=%d\n", map.get("Yolo"));
    qDebug("map[\"Tanguy\"]=%d\n", map.get("Tanguy"));


    QApplication a(argc, argv);
    MainWindow::instruction_duration = 200;
    w = new MapWindow(*map.root);
    w->show();
    return a.exec();
}
