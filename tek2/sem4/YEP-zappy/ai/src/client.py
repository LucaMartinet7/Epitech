#!/usr/bin/env python3
import socket
import argparse
import threading
import time
import sys
import ai.src.logic as logic

buffer_size = 1024

def connecting_to_server(server_ip, server_port):
    try:
        client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        client_socket.connect((server_ip, server_port))
        print("Successfully connected")
        return client_socket
    except Exception as e:
        print("Error in connecting to server", e)
        if client_socket:
            client_socket.close()
        return None

def send_data(client_socket, data):
    try:
        client_socket.sendall(data.encode())
        print("Sent: ", data)
    except Exception as e:
        print("Error in sending data", e)

def data_receiving(client_socket):
    try:
        data = client_socket.recv(buffer_size)
        if data:
            msg = data.decode().strip()
            print("Received: ", msg)
            return msg
        else:
            print("No data received")
            return None
    except Exception as e:
        print("Error in receiving data", e)
        return None

def handle_name(client_socket,team_name):
    answer = data_receiving(client_socket)
    if answer.strip() == "WELCOME":
        team_name = input("Enter your team name: ")
        send_data(client_socket, f"{team_name}\n")
        return True
    return False

def help():
    print("USAGE:\n\t./zappy_ai -p port -n name -h machine\n\nDESCRIPTION:")
    print("\t-p port\t\t\tthe port number")
    print("\t-n name\t\t\tthe name of the team")
    print("\t-m machine\t\tthe name of the machine; localhost by default")

def main():
    if '-help' in sys.argv:
        help()
        return

    parse = argparse.ArgumentParser()
    parse.add_argument("-p", dest="port", type=int, help="port number")
    parse.add_argument("-n", dest="name", type=str, help="name of the team")
    parse.add_argument("-m", dest="machine", type=str, nargs='?', help="name of the machine; localhost by default")

    args = parse.parse_args()

    server_ip = args.machine
    server_port = args.port
    team_name = args.name

    client_socket = connecting_to_server(server_ip, server_port)
    if client_socket:
        if handle_name(client_socket, team_name):
            logicAI = logic.AILogic(team_name, sys.argv)
            while True:
                logicAI.decision_taking(client_socket)
                response = data_receiving(client_socket)
                if response is None or response.strip() == "ko":
                    print("ko")
                    break
        client_socket.close()
    else:
        print("Failed to connect to server")

if __name__ == "__main__":
    main()