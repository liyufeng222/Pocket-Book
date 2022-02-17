#include "dashboard.h"

DashBoard::DashBoard()
{
    //dashboard
    tb.set_bound(sf::Vector2f(1700,730));
    tb.set_position(sf::Vector2f(50,130));
    tb.set_OutLine_color(sf::Color::Cyan);
    tb.set_OutLine_thick(2);

    topic.set_string("Detail: ");
    topic.set_size(CHARACTERS_SIZE_1);
    topic.set_color(sf::Color::Cyan);
    topic.set_position(sf::Vector2f{30,50});

    balance.set_string("Balance: ");
    balance.set_size(CHARACTERS_SIZE_1);
    balance.set_color(sf::Color::Blue);
    balance.set_position(sf::Vector2f{1200,780});

    value.set_string("");
    value.set_size(CHARACTERS_SIZE_1);
    value.set_color(sf::Color::Cyan);
    value.set_position(sf::Vector2f{1450,780});
}

//from the sf::Drawable class
void DashBoard::draw(sf::RenderTarget& window, sf::RenderStates states) const{

    window.draw(tb);
    window.draw(topic);
    window.draw(balance);
    window.draw(value);

    for(Single_Term st: terms){
        window.draw(st);
    }
}

// from EventHandler
void DashBoard::addEventHandler(sf::RenderWindow& window, sf::Event event){
    int count = 0;
    for(vector<Single_Term>::iterator it = terms.begin();it != terms.end();++it){
        if(MouseEvents<sf::RectangleShape>::mouseClicked((*it).get_text_box(), window)){
            current_index = count;
            is_update = false;
            //cout << "Current_index: "<<current_index<<endl;
        }
        count++;
    }
}
void DashBoard::update(){
    int count = 0;
    float y_start = 150;
    for(vector<Single_Term>::iterator it = terms.begin();it != terms.end();++it){
        if(current_index == count){
            (*it).set_box_outline(true);
        }else{
            (*it).set_box_outline(false);
        }
        (*it).set_position(sf::Vector2f(75,y_start));
        y_start += CHARACTERS_SIZE_2 + 10;
        count++;
    }

    string amount = to_string(get_total());
    amount = amount.substr(0, amount.size()-4);    //get only two decimal
    value.set_string(amount);
}

//from SnapshotInterface
SnapShot& DashBoard::getSnapshot(){
    std::vector<pair<string,double>> temp;
    //cout<<"SP:"<<endl;
    for(Single_Term term : terms){
        temp.push_back(pair<string,double>(term.get_name(), term.get_Value()));
        //cout<<term.get_name()<<"    "<<term.get_Value()<<endl;
    }
    sp.set_terms(temp);

    return sp;
}
void DashBoard::applySnapshot(const SnapShot& snapshot){
    terms.clear();

    std::vector<pair<string,double>> temp = snapshot.get_terms();
    cout<<temp.size()<<endl;
    std::vector<pair<string,double>>::iterator it;
    for(it = temp.begin(); it != temp.end(); ++it){
        if(it->second >= 0){
            add_item(it->first, to_string(it->second), "Income");
        }else{
            add_item(it->first, to_string(it->second), "Cost");
        }
    }
}


void DashBoard::add_item(string item_name, string amount_value, string type){
    //cout<<"Here"<<endl;
    Single_Term st(item_name, amount_value, type);
    //Single_Term st;
    //st.edit(item_name, amount_value, type);
    terms.push_back(st);
    //cout<<"Here"<<endl;
}
void DashBoard::edit_item(string item_name, string amount_value, string type){
    vector<Single_Term>::iterator walker = terms.begin();
    advance(walker, current_index);
    (*walker).edit(item_name, amount_value, type);
}
void DashBoard::delect(){
    if(!terms.empty() && current_index >= 0 && current_index < terms.size()){
        vector<Single_Term>::iterator it = terms.begin();
        advance(it, current_index);
        terms.erase(it);
    }
}

double DashBoard::get_total(){
    double total = 0;
    for(vector<Single_Term>::iterator it = terms.begin();it != terms.end();++it){
        total += (*it).get_Value();
    }
    return total;
}

bool DashBoard::get_is_update() const{
    return is_update;
}
void DashBoard::set_is_update(){
    is_update = true;
}

string DashBoard::get_current_name(){
    vector<Single_Term>::iterator walker = terms.begin();
    advance(walker, current_index);
    return (*walker).get_name();
}
string DashBoard::get_current_amount(){
    vector<Single_Term>::iterator walker = terms.begin();
    advance(walker, current_index);
    return (*walker).get_amount();
}
string DashBoard::get_current_type(){
    vector<Single_Term>::iterator walker = terms.begin();
    advance(walker, current_index);
    return (*walker).get_type();
}

void DashBoard::output_file(string file_address){
    ofstream myfile(file_address);
    if(myfile.is_open()){
        //content
        /*for(vector<Single_Term>::iterator it = terms.begin();it != terms.end();++it){
            myfile<<
        }*/
        for(Single_Term term : terms){
            string amount = to_string(term.get_Value());
            amount = amount.substr(0, amount.size()-4);
            myfile<<term.get_name() + "     " + amount<<endl;
        }
        string total = to_string(get_total());
        total = total.substr(0, total.size()-4);
        myfile<<"                   Balance: "+total;
        myfile.close();
    }else{
        cout<<"Can not out the file";
    }
}

void DashBoard::open_file(string file_address){
    string line;
    string name;
    double amount;
    ifstream myfile(file_address);
    stringstream ss;
    if(myfile.is_open()){
        while(getline(myfile, line)){
            ss<<line;
            ss>>name>>amount;
            if(name!="Balance:"){
                if(amount >= 0){
                    add_item(name, to_string(amount), "Income");
                }else{
                    add_item(name, to_string(-1*amount), "Cost");
                }
            }
            ss.clear();
        }

        myfile.close();
    }
}
