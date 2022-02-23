package main

import "net/http"

type Listener struct {
	ListenPort int
	gConfig    Config
	s          *http.Server
}

func (list *Listener) Listen() {
	router := mux.NewRouter()

	router.PathPrefix("/agent/{uuid}/{function}").HandlerFunc(HandleAgentHTTPRequests())

	list.s = &http.Server{
		Handler: router,
		Addr:    ":" + string(list.ListenPort),
	}

	go list.s.ListenAndServe()

}

func NewListener(port int) Listener {
	l := Listener{}

	l.ListenPort = port
	return l
}

func HandleAgentHTTPRequests() func(w http.ResponseWriter, r *http.Request) {
	//Route will be the requested URL query string
	// All strings will be stored in the config.json to make it easier to change
	return func(w http.ResponseWriter, r *http.Request) {
		vars := mux.Vars(r)

		uuid := vars["uuid"]
		route := vars["function"]

		switch route {
		case gConfig.Listener.CheckInCmd:
			//checkin()
			break
		case gConfig.Listener.DownloadCmd:
			break
		case gConfig.Listener.UploadCmd:
			break
		case gConfig.Listener.ExecCmd:
			break
		case gConfig.Listener.ExecAssemblyCmd:
			break

		}
	}
}
