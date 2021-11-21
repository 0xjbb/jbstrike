from flask import Flask
import database

app = Flask(__name__)

# GET TASKS
# implant routes
@app.route('/task/get/<agent_id>')
def task_handler(agent_id):
    return ""

@app.route("/ret/<agent_id>", methods=['post'])
def return_data(agent_id):


    return 1

# client routes
@app.route('/task/set/<agent_id>', methods=['GET'])
def set_task(agent_id):
    return 1


if __name__ == "__main__":
    app.run()
