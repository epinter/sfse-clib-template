#pragma once

/*
MIT License

Copyright (c) 2023 Emerson Pinter

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
 */

template <class T>
class SfseMessagingListener {
    protected:
        SfseMessagingListener() = default;

    private:
        SfseMessagingListener(SfseMessagingListener&) = delete;
        SfseMessagingListener& operator=(SfseMessagingListener&&) = delete;
        void operator=(SfseMessagingListener&) = delete;

    public:
        ~SfseMessagingListener() = default;

        // This plugin is finishing load.
        virtual void onLoad(){};

        // All plugins have finished running SFSEPlugin_Load.
        virtual void onPostLoad(){};

        // All kPostLoad message handlers have run.
        virtual void onPostPostLoad(){};

        // All plugins have loaded, main menu is now active.
        virtual void onPostDataLoaded(){};

        // All plugins have loaded and all PostDataLoad events have handled
        virtual void onPostPostDataLoaded(){};

        auto registerListener() {
            if (!SFSE::GetMessagingInterface()->RegisterListener([](SFSE::MessagingInterface::Message* message) {
                    switch (message->type) {
                        case SFSE::MessagingInterface::kPostLoad:
                            T::getInstance().onPostLoad();
                            break;
                        case SFSE::MessagingInterface::kPostPostLoad:
                            T::getInstance().onPostPostLoad();
                            break;
                        case SFSE::MessagingInterface::kPostDataLoad:
                            T::getInstance().onPostDataLoaded();
                            break;
                        case SFSE::MessagingInterface::kPostPostDataLoad:
                            T::getInstance().onPostPostDataLoaded();
                            break;
                    }
                })) {
                SFSE::stl::report_and_fail("Unable to register message listener.");
            }
        }
};
