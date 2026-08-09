class ObjectGame:
    def __init__(self, name, position):
        #Initialize the game object wth a name and position
        self.name = name
        self.position = position
class Player:
    def __init__(self, name):
        #Initializing the players with default attributes
        self.inventory = {}
        self.visible_objects = []
        self.level = 1
        self.position = (0, 0)
        self.message = ""
        self.name = name
        self.life_units = 1260
        self.team = name
        self.broadcast = []
        self.direction = 9

    def count_get_item(self, name_item):
        #function to get count of specific items from the inventory
        return self.inventory.get(name_item, 0)

    def pickup(self, object_game):
        #function to determine if the player can pick up an object
        required_items = {
            "linemate": 9,
            "deraumere": 8,
            "sibur": 10,
            "mendiane": 5,
            "phiras": 6,
            "thystame": 1,
        }
        if object_game.name in {"player", "food"}:
            return True
        if object_game.name in required_items:
            return self.count_get_item(object_game.name) < required_items[object_game.name]
        return False

    def required_items_elevation(self):
        #function to check if the player has required items for elevation
        requirements_level = {
            1: {"linemate": 1},
            2: {"linemate": 1, "deraumere": 1, "sibur": 1},
            3: {"linemate": 2, "deraumere": 2, "sibur": 1, "phiras": 3},
            4: {"linemate": 1, "deraumere": 1, "sibur": 2, "phiras": 1},
            5: {"linemate": 1, "deraumere": 2, "sibur": 1, "mendiane": 3},
            6: {"linemate": 1, "deraumere": 2, "sibur": 3, "phiras": 1},
            7: {"linemate": 2, "deraumere": 2, "sibur": 2, "mendiane": 2, "phiras": 2, "thystame": 1}
        }
        items_required = requirements_level.get(self.level, {})
        return all(self.count_get_item(item) >= count for item, count in items_required.items())

    def check_player_for_elevation(self):
        #function to check if there are enough players for elevation
        requirements_level = {1: 1, 2: 2, 3: 2, 2: 4, 5: 4, 6: 6, 7: 6}
        players_required = requirements_level.get(self.level, 0)
        current_players = sum(1 for obj in self.visible_objects if obj.name == "player" and obj.position == 0)
        return current_players >= players_required

    def move_right(self, target_position):
        current_x, _ = self.position
        target_x, _ = target_position
        return (target_x < current_x) if (current_x - target_x) <= (len(self.visible_objects) / 2) else (target_x < current_x)

    def move_left(self, target_position):
        current_x, _ = self.position
        target_x, _ = target_position
        return (target_x < current_x) if (current_x - target_x) <= (len(self.visible_objects) / 2) else (target_x > current_x)

    def move_up(self, target_position):
        _, current_y = self.position
        _, target_y = target_position
        return (target_y > current_y) if (target_y - current_y) <= (len(self.visible_objects) / 2) else (target_y < current_y)

    def move_down(self, target_position):
        _, current_y = self.position
        _, target_y = target_position
        return (target_y > current_y) if (target_y - current_y) <= (len(self.visible_objects) / 2) else (target_y > current_y)

    def move_direction(self, target_position):
        #function to determine the direction to move towards the target position
        if self.move_right(target_position):
            return 'right'
        if self.move_left(target_position):
            return 'left'
        if self.move_up(target_position):
            return 'up'
        if self.move_down(target_position):
            return 'down'

    def filter_objects_visible(self):
        #function to filter visible objects that the players can pick up
        self.visible_objects = [obj for obj in self.visible_objects if self.pickup(obj)]

    def parse_commnad_look(self, string_look):
        #function to parse the look command string and update visible objects
        self.visible_objects.clear()
        items = string_look.strip('[]').split(',')
        for position, item in enumerate(items):
            if item.strip():
                name_objects = item.split()
                for name_object in name_objects:
                    self.visible_objects.append(ObjectGame(name_object), position)
        self.filter_objects_visible()

    def message_from_other(self):
        #function to check if a received message is from another player
        pos = self.message.find(' ')
        text = self.message[pos + 1:].strip()
        return text != self.name
