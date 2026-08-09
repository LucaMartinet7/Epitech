"use client";

import { FormSubmit } from "@/components/form/form-submit";
import { FormTextarea } from "@/components/form/form-textarea";
import { Button } from "@/components/ui/button";
import { Plus, X } from "lucide-react";
import { useAction } from "@/hooks/use-action";
import { createCard } from "@/actions/create-card";
import { useRef, forwardRef, ElementRef, KeyboardEventHandler, FormEvent, useState } from "react";
import { useParams } from "next/navigation";
import { useEventListener, useOnClickOutside } from "usehooks-ts";
import { toast } from "sonner";

interface CardFormProps {
    listId: string;
    enableEditing: () => void;
    disableEditing: () => void;
    isEditing: boolean;
}

export const CardForm = forwardRef<HTMLTextAreaElement, CardFormProps>(({ listId, enableEditing, disableEditing, isEditing }, ref) => {
    const params = useParams();
    const formRef = useRef<ElementRef<"form">>(null);
    const [title, setTitle] = useState("");
    const { execute, FieldErrors } = useAction(createCard, {
        onSuccess: (data: { title: string }) => {
            toast.success(`Card "${data.title}" created successfully`);
            disableEditing();
        },
        onError: (error) => {
            console.error("Failed to create card", error);
            toast.error("Failed to create card");
        },
    });

    const onKeyDown = (e: KeyboardEvent) => {
        if (e.key === "Escape") {
            disableEditing();
        }
    };

    useOnClickOutside(formRef, disableEditing);
    useEventListener("keydown", onKeyDown);

    const onTextareaKeyDown: KeyboardEventHandler<HTMLTextAreaElement> = (e) => {
        if (e.key === "Enter" && !e.shiftKey) {
            e.preventDefault();
            formRef.current?.requestSubmit();
        }
    };

    const onSubmit = (event: FormEvent<HTMLFormElement>): void => {
        event.preventDefault();
        const formData = new FormData(event.currentTarget);
        const title = formData.get("title") as string;
        const listId = formData.get("listId") as string;
        const boardId = params.boardId as string;
        execute({ title, listId, boardId });
    };

    if (isEditing) {
        return (
            <form ref={formRef} onSubmit={onSubmit} className="m-1 py-0.5 px-1 space-y-4">
                <FormTextarea
                    id="title"
                    onKeyDown={onTextareaKeyDown}
                    ref={ref}
                    placeholder="Enter a title for this card..."
                    errors={FieldErrors}
                    defaultValue={title}
                />
                <input hidden id="listId" name="listId" value={listId} />
                <div className="flex items-center gap-x-1">
                    <FormSubmit>
                        Add Card
                    </FormSubmit>
                    <Button onClick={disableEditing} size="sm" variant="ghost">
                        <X className="h-5 w-5" />
                    </Button>
                </div>
            </form>
        );
    }

    return (
        <div className="pt-2 px-2">
            <Button
                onClick={enableEditing}
                className="h-auto px-2 py-1.5 w-full justify-start text-muted-foreground text-sm"
                size="sm"
                variant="ghost"
            >
                <Plus className="h-4 w-4 mr-2" />
                Add a card
            </Button>
        </div>
    );
});

CardForm.displayName = "CardForm";