# Netlore - Simple, lightweight experimental browers.

## Goal and my thoughts..

Netlore will be a simple lightweight experimental browser and web engine fully written in C. In my perspective it will be a fun and teaching project in which I can show all of my passion for programming. Writing a fully browser that is fully compatible with all new standards of web is nearly impossible by doing it for yourself, if I had a team writing it would go more smoother. My goals for netlore are simple:

- Be compatible with HTML 4.0
- Get simple CSS 2.0 working or even 3.0
- Support JavaScript engine (like NodeJS or V8)
- Create a good looking UI
- Write for my own HTML, CSS Parser
- And mostly have fun!

Did I just written a simple TODO list? Maybe but that doesn’t matter really. These are the things I want to have in Netlore, I fully understand that writing i for myself will be the biggest programming goal I can success but I fully want to have fun and try it for my self.

---

## Components of Netlore

Netlore will be divide in some parts, for example UI system will have other name than HTML/CSS Parser, every component will add up to netlore. Some component will be named after the names of gods in Norse mythology and others not. Here’s the full list of Netlore components. All of them will be in one repository on github: `/netlore-org/netlore`

- **Netlore** (Browser)
    - **Bolly** (Web engine)
        - **Heimdall** (UI & Window Manager) - Everything that want’s to be on screen need to go by Heimdall it’s a simple UI & Window Manager library
        - **Njord** (HTML, CSS Parser) - Into Njord goes every HTML/CSS code in which it would be lexer and parsed and return a DOM element
        - **Balder** (URL Parser) - Simple URL parser that would return a simple structure with URL
        - **Loki** (Rendering Engine) - Loki would look at DOM tree and say:
            
            > “That’s pretty easy, let’s show it on the screen.. I will just call Heimdall”
            > 
        - **Freja** (Network caller) - Component in which every HTTPS request goes by.
    - **Fredric** (Build system.. Why would it have even a name lol?)

---

## What will I use to create it?

What will I use while creating netlore, I can just answer C and go on with this text but let’s divide it in some parts.

| Component type | Name | Programming Language | Libraries |
| --- | --- | --- | --- |
| UI & Window Manager | Heimdall | C | SDL2 SDL_image |
| HTML, CSS Parser | Njord | C | None |
| URL Parser | Balder | C | None |
| Rendering Engine | Loki | C | None |
| Network caller | Freja | C | CURL |
| Sound | Aegir | C | libsndfile, OpenAL |
| Build system | Fredric | Makefile, Python | None (is there even a library for Makefile lmao) |

  *As you see i really like C :3*

---

## To do list..

- [ ]  **Heimdall** (UI & Window Manager)
    - [X]  *Create simple Window creator*
    - [X]  *Simple rendering system*
    - [ ]  *UI Manager*
    - [ ]  *UI Components*
        - [ ]  *Inputs*
        - [ ]  *Buttons*
        - [ ]  *Menu*
        - [ ]  *Text*
- [ ]  **Njord** (HTML, CSS Parser)
    - [ ]  *HTML Parser*
    - [ ]  *CSS Parser*
    - [ ]  *Create DOM nodes from them*
- [ ]  **Balder** (URL Parser)
    - [ ]  *Is URL correct*
    - [ ]  *Parse URL into structure*
- [ ]  **Loki** (Rendering Engine)
    - [ ]  *Render DOM*
- [ ]  **Freja** (Network caller)
    - [ ]  *Request HTTPS host and get the HTML*
    - [ ]  *Websocket*
- [ ]  **Aegir** (Sound player)
    - [ ]  Setup libsndfile
    - [ ]  Play sound by using OpenAI
- [ ]  **Fredric** (Build system)
    - [ ]  *Toolchain installer*
        - [ ]  *SDL2*
        - [ ]  *CURL*
    - [ ]  *Build whole engine*

### Notion.so version [here!](https://wild-curler-b6f.notion.site/Netlore-Simple-lightweight-experimental-browers-0640eac76821466fa6ea76a22e59dd1d)
