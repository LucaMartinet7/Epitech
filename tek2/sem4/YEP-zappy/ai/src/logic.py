import ai.src.player as player

class Decision:
    def __init__(self):
        self.action = None
        self.parameters = None
        self.sent = False

class AILogic:
    def __init__(self, ac, av):
        self.player = player.Player(ac)  # Assuming ac is used correctly for initializing player
        self.decision = Decision()
        self.check = 0
        self.running = False

    def decision_taking(self, client_socket):
        if (self.player.message_from_other() and self.player.level > 1 and
            self.player.required_items_elevation()):
            if self.player.check_player_for_elevation():
                self.decision.action = "Incantation"
                self.player.message = ""
                send_data(client_socket, self.decision.action)
                return
        
        if self.player.required_items_elevation():
            if self.player.check_player_for_elevation():
                self.decision.action = "Incantation"
                send_data(client_socket, self.decision.action)
                return
            self.decision.action = "Broadcast"
            self.decision.parameters = self.player.name
            send_data(client_socket, f"{self.decision.action} {self.decision.parameters}")
            return
        
        if not self.player.visible_objects:
            self.decision.action = "Look"
            self.player.position = (0, 0)
            self.player.direction = "AHEAD"
            send_data(client_socket, self.decision.action)
            return
        
        if self.check % 5 == 0:
            self.decision.action = "Inventory"
            send_data(client_socket, self.decision.action)
            return
        
        self.check += 1
        target_position = self.player.position
        direction = self.player.move_direction(target_position)
        if direction:
            self.decision.action = f"Move {direction}"
            send_data(client_socket, self.decision.action)

def send_data(client_socket, data):
    try:
        client_socket.sendall(data.encode())
        print("Sent: ", data)
    except Exception as e:
        print("Error in sending data", e)