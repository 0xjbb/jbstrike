import encode


class Task:
    agent_id = ""

    def __init__(self, agent_id):
        self.agent_id = agent_id

    def get(self):
        return encode(b"shell|test")

    def build(self, data):
        return data