#include "filetree.h"

float FileTree::bottom = 0;

FileTree::FileTree()
{
    push("Project", "Project");
    root->set_state(true);


    //default tree
    /*root->add_child(Image::FOLDER, "Folder2");
    root->add_child(Image::FOLDER, "Folder3");*/
    root->add_child(Image::FILE, "0.txt");
    root->add_child(Image::FILE, "1.txt");
    root->add_child(Image::FILE, "2.txt");
}
void FileTree::push(std::string parent, std::string item){
    push(root, parent, item);
}

//draws the root node of the tree
void FileTree::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(*root);
}

//does nothing now
void FileTree::applySnapshot(const SnapShot& snapshot){

}

//calls the traverse function to add the event handlers to each node
void FileTree::addEventHandler(sf::RenderWindow& window, sf::Event event){
    root->addEventHandler(window,event);
}

//does nothing now
void FileTree::update(){
    root->update();
}
//does nothing now
SnapShot& FileTree::getSnapshot(){

}


//private
void FileTree::push(FileNode*& root, std::string parent, std::string item){

    if(root == nullptr){
        root = new FileNode(Image::FOLDER, item, DEFAULT_SIZE, initPosition);
        return;
    }
    for(map<string, FileNode*>::iterator it = root->begin();
        it != root->end(); ++it)
    {
        if(it->first == parent){
            it->second->add_child(Image::FILE, item);
            return;
        }else if(!it->second->isLeaf()){
            push(it->second, parent, item);
        }

    }

    root->add_child(Image::FOLDER, item);

    /*if(!root->isLeaf()){
        for(map<string, FileNode*>::iterator it = root->begin();
            it != root->end(); ++it)
        {
            if(it->first == parent){
                it->second->add_child(Image::FILE, item);
                return;
            }else{
                push(it->second, parent, item);
            }

        }
    }else{
        root->add_child(Image::FOLDER, item);
    }

    if(item < root->data){
        if(root->left != nullptr){
            add(item, root->left);
        }else{
            root->left = generate_node(item);
        }
    }
    if(item > root->data || item == root->data){
        if(root->right != nullptr){
            add(item, root->right);
        }else{
            root->right = generate_node(item);
        }
    }*/
}

void FileTree::traverse(FileNode* &root, sf::RenderWindow& window, sf::Event event){

}
