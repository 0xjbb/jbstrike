package webserver

import (
	"github.com/0xjbb/jbstrike/teamserver/pkg/cfg"
	"github.com/0xjbb/jbstrike/teamserver/pkg/listeners"
	"github.com/gorilla/mux"
	"net/http"
)

type ServerHandler struct {
	ServerPort int
	Listeners  []listeners.Listener
	s          *http.Server
}

func (sHandler *ServerHandler) Start() {
	sHandler.s = &http.Server{}

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

func HandleServerRequests() *mux.Router {
	router := mux.NewRouter()

	/*
		/client/listener/start --
		/client/listener/stop -- pass ID as post var
		/client/listener/remove -- pass ID as post var
		/client/listeners/list

		/client/agents/list
		/client/agent/{id}/{command}
	*/

	return router
}
