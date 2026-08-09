"use client";

import { Button } from "@/components/ui/button";
import { Popover, PopoverClose, PopoverTrigger, PopoverContent } from "@/components/ui/popover";
import { MoreHorizontal, X } from "lucide-react";
import { useAction } from "@/hooks/use-action";
import { toast } from "sonner";
import { deleteBoard } from "@/actions/delete-board";

interface BoardOptionsProps {
    id: string;
}

export const BoardOptions = ({ id }: BoardOptionsProps) => {
    const { execute } = useAction(deleteBoard, {
        onError: (error) => {
            toast.error("Failed to delete board");
            console.error("Failed to delete board", error);
        },
    });

    const onDelete = () => {
        execute({ id });
    }


    return (
        <Popover>
            <PopoverTrigger asChild>
                <Button variant="transparent" className="h-auto w-auto p-2">
                    <MoreHorizontal className="h-4 w-4" />
                </Button>
            </PopoverTrigger>
            <PopoverContent className="px-0 pt-3 pb-3" align="start" side="bottom">
                <div className="text-sm font-medium text-center text-neutral-600 pb-4">
                    Board ACtions
                </div>
            <PopoverClose asChild>
                <Button className="h-auto w-auto absolute p-2 top-2 right-2 text-neutral-600" variant="ghost">
                    <X className="h-4 w-4" />
                </Button>
            </PopoverClose>
            <Button variant="ghost" className="rounded-none w-full h-auto p-2 px-5 justify-start font-normal text-sm" onClick={onDelete}>
                Delete Board
            </Button>
            </PopoverContent>
        </Popover>
    );
}