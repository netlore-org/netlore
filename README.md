# Netlore - Simple, lightweight experimental browers.

## About

**Netlore** is a simple, lightweight **experimental** browser and web engine written in C. It is a passion project that aims to showcase my love for programming while also serving as a fun and educational endeavor. Developing Netlore alone can be challenging, but I believe that I can, **contributing is wanted of course**.

## Project Goals

The main objectives for Netlore are as follows:
- **Compatibility with HTML 4.0**: Netlore aims to be compatible with the HTML 4.0 standard, allowing users to browse websites built using this version.
- **Support for CSS 2.0 or even 3.0**: Netlore seeks to provide basic support for CSS 2.0 and possibly CSS 3.0. This will allow users to render web pages with styled content and enhance the overall browsing experience.
- J**avaScript Engine Support**: Netlore intends to incorporate a JavaScript engine, such as Node.js or V8, enabling users to interact with dynamic and interactive web content.
- **User Interface Design**: The project aims to create a visually appealing and user-friendly interface for the browser, ensuring a pleasant browsing experience.
- **Custom HTML and CSS Parser**: Netlore will feature its own HTML and CSS parser, developed from scratch. This will not only enhance the understanding of these technologies but also provide flexibility and customization options.
- **Enjoyment and Personal Growth**: Above all, Netlore is meant to be an enjoyable project that allows me to explore programming concepts, learn new skills, and challenge myself. The primary objective is personal growth and satisfaction.

## Disclaimer

It's important to note that developing a fully functional browser compatible with all the latest web standards is an enormous undertaking. While I am fully committed to the project, I understand the challenges and limitations associated with developing such a complex piece of software independently. However, the primary goal of Netlore remains to have fun, enjoy the programming process, and challenge myself.

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

## To do list..

- [X]  **Heimdall** (UI & Window Manager)
    - [X]  *Create simple Window creator*
    - [X]  *Simple rendering system*
    - [X]  *UI Manager*
    - [X]  *UI Components*
        - [X]  *Inputs*
        - [X]  *Buttons*
        - [X]  *Menu*
        - [X]  *Text*
- [ ]  **Njord** (HTML, CSS Parser)
    - [X]  *HTML Parser*
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
    - [X]  *Build whole engine*
