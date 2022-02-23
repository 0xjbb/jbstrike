package main

import "net/http"

type ServerHandler struct {
	ServerPort int
	Listeners  []Listener
	s          *http.Server
}

func (sHandler *ServerHandler) Start() {
	sHandler.s = &http.Server{}

}

// Add some error checknig later
func (sHandler *ServerHandler) ParseConfig(sConfig Config) {
	sHandler.ServerPort = sConfig.Server.DefaultPort
}

func NewServer(gConfig Config) ServerHandler {
	s := ServerHandler{}

	s.ParseConfig(gConfig)

	return s
}

func HandleServerRequests(route string) {
	/*
		/client/listener/start --
		/client/listener/stop -- pass ID as post var
		/client/listener/remove -- pass ID as post var
		/client/listeners/list

		/client/agents/list
		/client/agent/{id}/{command}
	*/
	switch route {
	case "/client/listener/start":
		//l := Listener{}
		//go l.Listen()
		break
	case "/client/listener/stop":

		break
	case "/client/listener/remove":

		break
	case "/client/listeners/list":
		// list id:port for all listeners.
		break

	case "/client/agents/list":
		// list all agents, their listeners and some info.
		break
	case "/client/agent/{id}/{command}": // figure this out.

		break
	default:
		// error.
		break

	}
}
