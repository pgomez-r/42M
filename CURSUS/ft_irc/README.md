# ft_irc

This project is an IRC server developed in C++ 98 standard for the ft_irc project of 42 school. The server allows multiple clients to connect, join channels, and communicate in real-time.

## Features

- Handles multiple clients simultaneously.
- Supports basic IRC commands such as CAPLS, PASS, NICK, USER, JOIN, PRIVMSG, KICK, INVITE, TOPIC, MODE, WHO, QUIT.
- Developed following the RFC 1459 standard.
- Tested with HexChat IRC client.

## Usage

1. Clone the repository:
    ```sh
    git clone https://github.com/fclaus-g/ft_irc ft_irc
    cd ft_irc
    ```

2. Build the project:
    ```sh
    make
    ```

3. Run the server:
    ```sh
    ./ircserv <port> <password>
    ```

4. Access the server via netcat or an IRC client (HexChat recommended):
    ```sh
    nc <server_ip> <port>
    ```

5. If connecting from netcat (terminal) follow instructions (PASS + NICK)

6. If using HexChat client, set password and nick/user/realname before trying to connect to the server

## Example

To start the server on port 6667 with password "mypassword":
```sh
./ircserv 6667 mypassword
