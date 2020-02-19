#include <gtest/gtest.h>
#include "con_handler.hpp"

TEST(stream_test, is_data_correct_test){
    io_service io_serv; 

    // Server
    ip::tcp::endpoint endpoint_server(ip::tcp::v4(), 9999);

    ip::tcp::acceptor acceptor_server( 
        io_serv, endpoint_server); 


    boost::shared_ptr<ip::tcp::socket> server_socket_ptr(new ip::tcp::socket(io_serv));

    // Client
    boost::shared_ptr<ip::tcp::socket> client_socket_ptr(new ip::tcp::socket(io_serv));
  
    client_socket_ptr->
        connect( 
            ip::tcp::endpoint( 
                ip::address::from_string("127.0.0.1"), 9999));
  
    // Connection
    acceptor_server.accept(*server_socket_ptr); 

    ConHandler server(io_serv, server_socket_ptr);
    ConHandler client(io_serv, client_socket_ptr);

    server.set_message("stream_test");
    server.send_message();
    client.recive_data();

    ASSERT_EQ("stream_test", client.get_data());
}

TEST(stream_test, is_empty_string_send){
    io_service io_serv; 

    // Server
    ip::tcp::endpoint endpoint_server(ip::tcp::v4(), 9999);

    ip::tcp::acceptor acceptor_server( 
        io_serv, endpoint_server); 


    boost::shared_ptr<ip::tcp::socket> server_socket_ptr(new ip::tcp::socket(io_serv));

    // Client
    boost::shared_ptr<ip::tcp::socket> client_socket_ptr(new ip::tcp::socket(io_serv));
  
    client_socket_ptr->
        connect( 
            ip::tcp::endpoint( 
                ip::address::from_string("127.0.0.1"), 9999));
  
    // Connection
    acceptor_server.accept(*server_socket_ptr); 

    ConHandler server(io_serv, server_socket_ptr);
    ConHandler client(io_serv, client_socket_ptr);

    server.set_message("\n");
    server.send_message();
    client.recive_data();

    ASSERT_EQ("\n", client.get_data());
}

int main(int argc, char* argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}