from channels.generic.websocket import WebsocketConsumer
import json

connections = []

class ControlConsumer(WebsocketConsumer):
    def connect(self):
        self.accept()
        connections.append(self)
        self.notify_users('User connected')

    def disconnect(self, close_code):
        if self in connections:
            connections.remove(self)
            self.notify_users('User disconnected')

    def receive(self, text_data):
        pass

    def notify_users(self, message):
        for connection in connections:
            try:
                connection.send(text_data=json.dumps({'message': message}))
            except:
                pass
