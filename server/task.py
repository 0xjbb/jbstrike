import encode


class Task():

    def get(self):
        return encode(b"shell|test")

    def build(self, data):
