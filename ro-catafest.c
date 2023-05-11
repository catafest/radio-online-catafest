#include <ncurses.h>
#include <stdlib.h> // for system() function

#define NUM_SUBMENU_ITEMS 3

int main()
{
    // Initialize ncurses
    initscr();

    // Turn off input echoing and enable special keys
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    // Create a window for the main menu
    WINDOW *menuwin = newwin(1, COLS, 0, 0);
    box(menuwin, 0, 0); // Add a border
    mvwaddstr(menuwin, 0, 2, "MAIN RADIO ONLINE MENU by catafest"); // Add a title

    // Define submenu items
    const char *submenu_items[NUM_SUBMENU_ITEMS] = {
        "Radio ClassicFMMP3.m3u",
        "Radio WCPE",
        "Exit"
    };

    // Create a submenu window
    WINDOW *subwin = newwin(NUM_SUBMENU_ITEMS+2, COLS-4, 2, 2);
    box(subwin, 0, 0); // Add a border
    for(int i=0; i<NUM_SUBMENU_ITEMS; i++)
    {
        mvwprintw(subwin, i+1, 2, submenu_items[i]); // Add a submenu item
    }
    wrefresh(subwin); // Refresh the submenu window

    // Highlight the first item in the submenu
    int highlight = 1;
    wbkgdset(subwin, COLOR_PAIR(1));
    mvwprintw(subwin, highlight, 2, submenu_items[highlight-1]);

    // Flag to indicate if the "Radio 001" option is playing or not
    int radio_playing = 0;

    // Refresh the screen to show changes
    refresh();
    wrefresh(menuwin);

    // Wait for user input
    int ch;
    bool stop_process = false; // Initialize stop flag

while(!stop_process)
{
    while((ch = getch()) != KEY_F(1) && ch != 27) // Exit on F1 key or ESC key
    {
        // Navigate submenu options using arrow keys
      
        switch(ch)
        {
            case KEY_UP:
                if(highlight > 1)
                    highlight--;
                break;
            case KEY_DOWN:
                if(highlight < NUM_SUBMENU_ITEMS)
                    highlight++;
                break;

            case '\n':
                if(highlight == 1) // "Radio ClassicFMMP3.m3u" option
                {
                    if(radio_playing == 0)
                    {
                        system("mpg123 -q --mono -r 8000 -b 0 -@ http://media-ice.musicradio.com/ClassicFMMP3.m3u &");
                        radio_playing = 1;
                    }
                    else
                    {
                        system("killall mpg123"); // Stop the audio playback
                        radio_playing = 0;
                    }

                }
		if(highlight ==  2) // "Radio WCPE" option
                {
                    if(radio_playing == 0)
                    {
                        system("mpg123 -q --mono -r 8000 -b 0 -@ http://www.ibiblio.org/wcpe/wcpe.pls &");
                        radio_playing = 1;
                    }
                    else
                    {
                        system("killall mpg123"); // Stop the audio playback
                        radio_playing = 0;
                    }
                }
                if(highlight ==  3) // "Radio WCPE" option
                {
                 
		   if(radio_playing == 0)
                    {
                        
                        radio_playing = 1;
                    }
                    else
                    {
                        system("killall mpg123"); // Stop the audio playback
                        radio_playing = 0;
                    }
                    	// Clean up
			delwin(subwin); // Delete the submenu window
			delwin(menuwin); // Delete the main menu window
			endwin();
                }
                break;
        
        }
        
	// Update the submenu highlighting
	wbkgdset(subwin, COLOR_PAIR(1));
	for(int i=0; i<NUM_SUBMENU_ITEMS; i++)
	{
	mvwprintw(subwin, i+1, 2, submenu_items[i]);
	}
	if(highlight <= NUM_SUBMENU_ITEMS)
	{
	wattron(subwin, A_REVERSE);
	mvwprintw(subwin, highlight, 2, submenu_items[highlight-1]);
	wattroff(subwin, A_REVERSE);
	}
	wrefresh(subwin);
	}
        system("killall mpg123");
        stop_process = true; // Set the stop flag
 
	// Clean up
	delwin(subwin); // Delete the submenu window
	delwin(menuwin); // Delete the main menu window
	endwin();
	return 0;
	}
}
