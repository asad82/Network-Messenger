# Network-Messenger
A MIRC like network messenger which allow numerous clients to connect to a server and chat and exchage files among themselves. The code is implemented in VC++ thus providing a GUI for chat among clients where as the server side interface provides information about the connected clients.

Functionalities implemented: 
----------------------------
Any type of File can be transferred, Open Message Forum, Private Chat by clients (ONE ON ONE), Multiple Clients

Implementation:
---------------
1.	SERVER: The server portion of the messenger maintains states of all the clients that are connected and forwards that list to all the clients when a change occurs such as: when some new clients joins the server or some already connected client leaves the server

2.	ONE ON ONE CHAT: The clients can also chat with each other by selecting a person from the online list visible to them. This communications is independent of the communication the client is doing with the server.

3.	FILE TRANSFER: The clients when chatting can also send and receive files from/to other clients. This functionality is available in the one on one chat that a client begins by double clicking on the person of his choice.

4.	OPEN FORUM: Also on the open message forum a message posted by one client is forwarded to all other clients by the server.

5.	The clients are listing on port 2000 for connections requests from other clients and on port 1500 for file transfer requests from other client that may be involved in a conversation.

6.	Beside this the server is listing on port 4000 by default which can be altered by the user.

7.	There are three classes that have been derived from the CasyncSocket. One is for the communication with the server the second is for client-client communication when they are involved in a conversation and the third is for file transfer.

8.	How Multiple Connections are Handled: The server handles multiple Client connections by maintaining an array of objects of the socket class i.e. one for each client and updates them with time.

9.	In short the MIRC messenger works perfectly and has also been tested on the university LAN.

10.	PICTURES: A pictures folder has been included which shows the program in action and different states and functionalities that have been implemented. Do see them to get a fair view. 

