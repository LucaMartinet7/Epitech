"use client";

import { FormSubmit } from "@/components/form/form-submit";
import { Button } from "@/components/ui/button";
import { Popover, PopoverClose, PopoverTrigger, PopoverContent } from "@/components/ui/popover";
import { Separator } from "@/components/ui/separator";
import { MoreHorizontal, X } from "lucide-react";
import { useAction } from "@/hooks/use-action";
import { deleteList } from "@/actions/delete-list";
import { toast } from "sonner";
import { ElementRef, useRef } from "react";
import { List } from "@prisma/client";

interface ListOptionsProps {
    data: List;
    onAddCard: () => void;
}

export const ListOptions = ({ data, onAddCard}: ListOptionsProps) => {
    const closeRef = useRef<ElementRef<"button">>(null);
    const { execute: executeDelete } = useAction(deleteList, {
        onSuccess: () => {
            toast.success("List deleted successfully");
            closeRef.current?.click();
        },
        onError: (error) => {
            console.error("Failed to delete list", error);
            toast.error("Failed to delete list");
        },
    });

    const onDelete = (FormData: FormData) => {
        const id = FormData.get("id") as string;
        const boardId = FormData.get("BoardId") as string;
        executeDelete({ id, boardId });
    }

    return (
        <Popover>
            <PopoverTrigger asChild>
                <Button className="h-auto w-auto p-2" variant="ghost">
                    <MoreHorizontal className="h-4 w-4" />
                </Button>
            </PopoverTrigger>
            <PopoverContent className="px-0 pt-3 pb-3" align="start" side="bottom">
                <div className="text-sm font-medium text-center text-neutral-600 pb-4">
                    List Actions
                </div>
                <PopoverClose ref={closeRef} asChild>
                    <Button className="h-auto w-auto absolute p-2 top-2 right-2 text-neutral-600" variant="ghost">
                        <X className="h-4 w-4" />
                    </Button>
                </PopoverClose>
                <Button variant="ghost" className="rounded-none w-full h-auto p-2 px-5 justify-start font-normal text-sm" onClick={onAddCard}>
                    Add Card
                </Button>
                <Separator />
                    <form action={onDelete}>
                        <input hidden id="id" name="id" value={data.id} />
                        <input hidden id="boardId" name="BoardId" value={data.boardId} />
                        <FormSubmit variant="ghost" className="rounded-none w-full h-auto p-2 px-5 justify-start font-normal text-sm" onClick={onAddCard}>
                            Delete List
                        </FormSubmit>
                    </form>
            </PopoverContent>
        </Popover>
    );
}