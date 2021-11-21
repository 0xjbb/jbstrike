import base64
"""
Change to AES later..
"""

def encode(data):
    return base64.b64encode(data)

def decode(data):
    return base64.b64decode(data)
