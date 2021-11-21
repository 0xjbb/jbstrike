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


@app.route("/ret/<agent_id>", methods=['post'])
def return_data(agent_id):

    return 1


if __name__ == "__main__":
    app.run()
