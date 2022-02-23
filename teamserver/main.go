package main

/**
Will just implement http for now, will upgrade to https at a later date.maybe

**/

func main() {
	gConfig := LoadConfig("~/.jbstrike/conf/config.json")

	server := NewServer(gConfig)
	server.Start()
}
