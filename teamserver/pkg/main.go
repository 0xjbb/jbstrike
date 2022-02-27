package main

/**
Will just implement http for now, will upgrade to https at a later date.maybe
**/
import (
	"github.com/0xjbb/jbstrike/teamserver/pkg/cfg"
	"github.com/0xjbb/jbstrike/teamserver/pkg/webserver"
)

var (
	gConfig cfg.Config
)

func main() {
	//check root or net_bind capability.
	gConfig := cfg.LoadConfig("~/.jbstrike/conf/cfg.json")
	server := webserver.NewServer(gConfig)
	server.Start()
}
