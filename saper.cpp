#include "stdafx.h"

#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include "MSSFMLView.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
/*
int main()
{
	srand(time(NULL));

	MinesweeperBoard board(10, 10, GameMode::EASY);
	MSBoardTextView view(board);
	MSTextController ctrl( board, view );

	board.debug_display();
	ctrl.play();
}
*/
/*
#include "stdafx.h"

#include <SFML/Network.hpp>
#include <iostream>
#include <windows.h>
using namespace std;

#define datasize 100

class UDP {

private:

	sf::UdpSocket socket;

public:

	bool send(char data[], sf::IpAddress ip, unsigned short port) {

		if (socket.send(data, datasize, ip, port) != sf::Socket::Done)
			return false;

		return true;
	}

	int receive(char data[], sf::IpAddress ip, unsigned short port) {

		unsigned int received;
		if (socket.bind(port) != sf::Socket::Done)
			return 0;

		if (socket.receive(data, datasize, received, ip, port) != sf::Socket::Done)
			return 0;

		return received;
	}

};


class TCP {

private:

	sf::TcpSocket socket;
	sf::TcpListener listener;

public:

	bool connect(sf::IpAddress ip, unsigned int port) {

		if (socket.connect(ip, port) != sf::Socket::Done)
			return false;
		return true;
	}

	bool send(char data[]) {

		if (socket.send(data, datasize) != sf::Socket::Done)
			return false;

		return true;
	}

	int listen(char data[], unsigned int port) {

		if (listener.listen(port) != sf::Socket::Done)
			return 0;

		unsigned int received;
		sf::TcpSocket client;

		while (true)
		{

			listener.accept(client);

			if (client.receive(data, datasize, received) == sf::Socket::Done)
				return received;

		}

	}

};


int main()
{

	sf::IpAddress ip = sf::IpAddress::getPublicAddress();
	cout << ip << endl;

	char data[datasize];
	TCP socket;

	bool cs;
	cin >> cs;

	if (cs == 1) {
		socket.connect(ip, 80);
		cout << socket.send("ala ma kota") << endl;
	}
	else
		cout << socket.listen(data, 80) << endl << data << endl;

	system("pause");
}
*/

#include <SFML/Graphics.hpp>

int main()
{
sf::RenderWindow oknoAplikacji( sf::VideoMode( 800, 600, 32 ), "Kurs SFML - http://cpp0x.pl" );
while( oknoAplikacji.isOpen() )
{
sf::Event zdarzenie;
while( oknoAplikacji.pollEvent( zdarzenie ) )
{
if( zdarzenie.type == sf::Event::Closed )
oknoAplikacji.close();

if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape )
oknoAplikacji.close();

if( zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.mouseButton.button == sf::Mouse::Middle )
oknoAplikacji.close();

}
oknoAplikacji.clear( sf::Color( 255, 0, 0 ) );
oknoAplikacji.display();
}
return 0;
}
