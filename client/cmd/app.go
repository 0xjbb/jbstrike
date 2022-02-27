package cmd

import (
	"fmt"
	"github.com/desertbit/grumble"
)

var App = grumble.New(&grumble.Config{
	Name:                  "jbstrike",
	Description:           "c2 go pew pew",
	Prompt:                "jbStrike » ",
	HelpHeadlineUnderline: true,
	HelpSubCommands:       true,

	Flags: func(f *grumble.Flags) {
		f.String("d", "directory", "DEFAULT", "set an alternative root directory path")
		f.Bool("v", "verbose", false, "enable verbose mode")
	},
})

func init() {
	fmt.Println("░░░░░██╗██████╗░░██████╗████████╗██████╗░██╗██╗░░██╗███████╗")
	fmt.Println("░░░░░██║██╔══██╗██╔════╝╚══██╔══╝██╔══██╗██║██║░██╔╝██╔════╝")
	fmt.Println("░░░░░██║██████╦╝╚█████╗░░░░██║░░░██████╔╝██║█████═╝░█████╗░░")
	fmt.Println("██╗░░██║██╔══██╗░╚═══██╗░░░██║░░░██╔══██╗██║██╔═██╗░██╔══╝░░")
	fmt.Println("╚█████╔╝██████╦╝██████╔╝░░░██║░░░██║░░██║██║██║░╚██╗███████╗")
	fmt.Println("░╚════╝░╚═════╝░╚═════╝░░░░╚═╝░░░╚═╝░░╚═╝╚═╝╚═╝░░╚═╝╚══════╝")
}
