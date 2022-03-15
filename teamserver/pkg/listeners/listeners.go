package listeners

import (
	"github.com/0xjbb/jbstrike/teamserver/pkg/cfg"
	"github.com/gorilla/mux"
	"net/http"
)

type Listener struct {
	Agents     []Agent
	ListenPort int
	gConfig    cfg.Config
	s          *http.Server
}

func (nList *Listener) Listen() {
	router := mux.NewRouter()

	router.PathPrefix("/agent/{uuid}/{function}").HandlerFunc(nList.HandleAgentHTTPRequests())

	nList.s = &http.Server{
		Handler: router,
		Addr:    ":" + string(nList.ListenPort),
	}

	go nList.s.ListenAndServe()

}

func NewListener(port int, gConfig cfg.Config) Listener {
	l := Listener{}

	l.ListenPort = port
	return l
}

func (nList *Listener) HandleAgentHTTPRequests() func(w http.ResponseWriter, r *http.Request) {
	//Route will be the requested URL query string
	// All strings will be stored in the cfg.json to make it easier to change
	return func(w http.ResponseWriter, r *http.Request) {
		vars := mux.Vars(r)

		//uuid := vars["uuid"]
		route := vars["function"]

		switch route {
		case nList.gConfig.Listener.CheckInCmd:
			//checkin()
			break
		case nList.gConfig.Listener.DownloadCmd:
			break
		case nList.gConfig.Listener.UploadCmd:
			break
		case nList.gConfig.Listener.ExecCmd:
			break
		case nList.gConfig.Listener.ExecAssemblyCmd:
			break

		}
	}
}
