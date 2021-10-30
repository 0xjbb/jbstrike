from flask import Flask

app = Flask(__name__)
# this is basically the team server portion of the shit, will write a client in cpp.

@app.route()
def task_handler():
    return ""


@app.route('/task/set', methods=['GET'])
def set_task():
    return 1
