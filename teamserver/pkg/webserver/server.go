package webserver

import (
	"fmt"
	"github.com/0xjbb/jbstrike/teamserver/pkg/cfg"
	"github.com/0xjbb/jbstrike/teamserver/pkg/listeners"
	"github.com/gorilla/mux"
	"net/http"
	"strconv"
)

type ServerHandler struct {
	ServerPort int
	Listeners  []listeners.Listener
	UsedPorts  []int
	s          *http.Server
}

func (sHandler *ServerHandler) Start() {
	sHandler.s = &http.Server{
		Handler: sHandler.HandleServerRequests(),
	}

	sHandler.s.ListenAndServe()
}

// Add some error checknig later
func (sHandler *ServerHandler) ParseConfig(sConfig cfg.Config) {
	sHandler.ServerPort = sConfig.Server.DefaultPort
}

func NewServer(gConfig cfg.Config) ServerHandler {
	s := ServerHandler{}

	s.ParseConfig(gConfig)

	return s
}

func (sHandler *ServerHandler) HandleServerRequests() *mux.Router {
	router := mux.NewRouter()
	/*
		/client/listener/start --
		/client/listener/stop -- pass ID as post var
		/client/listener/remove -- pass ID as post var
		/client/listeners/list

		/client/agents/list
		/client/agent/{id}/{command}
	*/
	router.HandleFunc("/client/listener/start", sHandler.StartListener)
	router.HandleFunc("/client/listener/stop", sHandler.StopListener)
	router.HandleFunc("/client/listener/remove", sHandler.RemoveListener)
	router.HandleFunc("/client/listeners/list", sHandler.ListListeners)

	router.HandleFunc("/client/agents/list", sHandler.ListAgents)               // Loop through all the listeners and get agents.
	router.HandleFunc("/client/agent/{id}/{command}", sHandler.NewAgentCommand) // Loop through all the listeners and check if they have an agent with the ID, then give them the command.

	return router
}

func (sHandler *ServerHandler) StartListener(w http.ResponseWriter, r *http.Request) {
	port, err := strconv.Atoi(r.FormValue("port"))

	if err != nil {
		fmt.Println("Error: ", err, " in function (sHandler *ServerHandler) StartListener")
	}

	listener := listeners.NewListener(port) // test port.
	sHandler.Listeners[port] = listener
	sHandler.UsedPorts = append(sHandler.UsedPorts, port) // Not sure if this is actually needed, will remove later if not.

	// do some chan magic here or w/e idk.
	go sHandler.Listeners[port].Listen()
}

func (sHandler *ServerHandler) StopListener(w http.ResponseWriter, r *http.Request) {

}

func (sHandler *ServerHandler) RemoveListener(w http.ResponseWriter, r *http.Request) {

}
func (sHandler *ServerHandler) ListListeners(w http.ResponseWriter, r *http.Request) {

}

func (sHandler *ServerHandler) ListAgents(w http.ResponseWriter, r *http.Request) {

}

func (sHandler *ServerHandler) NewAgentCommand(w http.ResponseWriter, r *http.Request) {

}
