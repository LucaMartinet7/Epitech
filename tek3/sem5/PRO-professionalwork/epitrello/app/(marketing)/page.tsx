import { Medal } from "lucide-react";
import Link from "next/link";

import {Poppins} from "next/font/google";

import { Button } from "@/components/ui/button";
import { cn } from "@/lib/utils";

const textFont = Poppins({
    subsets: ["latin"],
    weight: ["100", "200", "300", "400", "500", "600", "700", "800", "900"],
});

const MarketingPage = () => {
    return (
        <div className="flex items-center justify-center flex-col">
            <div className="flex items-center justify-center flex-col">
                <div className="mb-4 flex items-center border shadow-sm p-4 bg-amber-100 text-amber-700 rounded-full uppercase">
                    <Medal className="h-6 w-6 mr-2" />
                    No 1 task management tool (acording to me)
                </div>
                <h1 className="text-3xl md:text-6xl text-center text-neutral-800 mb-6">
                    Welcome to Epitrello
                    </h1>
            </div>
            <div className={cn(
                "text-sm md:text-xl text-neutral-400 mt-4 max-w-xs md:max-w-2xl text-center mx-auto", textFont.className,)}>
                Collaborate, manage projects, and reach new productivity peaks.
                From high rises to the home office, the way your team works is 
                unique- accomplish it all with Epitrello.
            </div>
            <Button className="mt-6" size="lg">
                <Link href="/sign-up">
                    Get started
                </Link>
            </Button>
        </div>
    );
};

export default MarketingPage;