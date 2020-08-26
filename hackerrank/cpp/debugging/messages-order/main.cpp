#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class Message {
public: 
    Message() {
        text = "";
        id=0;
    }
    Message(string t) {
        text = t;
        id=++cur_id;
    }
    const string& get_text() {
        return text;
    }
    
    bool operator < (const Message& m){
        if(id < m.id) return true;
        else return false;
    }
private:
    string text;
    int id;
    static int cur_id;
};

class MessageFactory {
public:
    MessageFactory() {}
    Message create_message(const string& text) {
        Message m(text);
        return m;
    }
};

int Message::cur_id=0;

class Recipient {
public:
    Recipient() {}
    void receive(const Message& msg) {
        messages_.push_back(msg);
    }
    void print_messages() {
        fix_order();
        for (auto& msg : messages_) {
            cout << msg.get_text() << endl;
        }
        messages_.clear();
    }
private:
    void fix_order() {
        sort(messages_.begin(), messages_.end());
    }
    vector<Message> messages_;
};

class Network {
public:
    static void send_messages(vector<Message> messages, Recipient& recipient) {
    // simulates the unpredictable network, where sent messages might arrive in unspecified order
        random_shuffle(messages.begin(), messages.end());         
        for (auto msg : messages) {
            recipient.receive(msg);
        }
    }
};



int main() {
    MessageFactory message_factory;
    Recipient recipient;
    vector<Message> messages;
    string text;
    while (getline(cin, text)) {
        messages.push_back(message_factory.create_message(text));
    }
    Network::send_messages(messages, recipient);
    recipient.print_messages();
}
